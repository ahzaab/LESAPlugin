#include "PCH.h"
#include "LevelUpMenu.h"
#include <cassert>
#include "Scaleform.h"
#include "SKSE/Logger.h"

namespace Scaleform
{
    LevelUpMenu::LevelUpMenu()
    {
        using Context = RE::UserEvents::INPUT_CONTEXT_ID;
        using Flag = RE::IMenu::Flag;

        menuFlags.set(Flag::kUpdateUsesCursor);
        auto loader = RE::BSScaleformManager::GetSingleton();
        auto success = loader->LoadMovieEx(this, SWF_NAME, [this](RE::GFxMovieDef* a_def) {
            using StateType = RE::GFxState::StateType;

            fxDelegate.reset(new RE::FxDelegate());
            fxDelegate->RegisterHandler(this);
            a_def->SetState(StateType::kExternalInterface, fxDelegate.get());
            fxDelegate->Release();

            auto logger = new Logger<LevelUpMenu>();
            a_def->SetState(StateType::kLog, logger);
            logger->Release();
        });

        if (!success) {
            assert(false);
            logger::critical("LevelUpMenu did not have a view due to missing dependencies! Aborting process!");
            std::abort();
        }

        menuFlags.set(Flag::kPausesGame, Flag::kModal, Flag::kDisablePauseMenu, Flag::kDisablePauseMenu);
        inputContext = Context::kMenuMode;

        InitExtensions();
        uiMovie->SetVisible(false);
    }


    void LevelUpMenu::Accept(RE::FxDelegateHandler::CallbackProcessor* a_cbReg)
    {
        a_cbReg->Process("CloseMenu", CloseMenu);
        a_cbReg->Process("Log", Log);
        a_cbReg->Process("PlaySound", PlaySound);

        // Add other funcationality here for GameDelegate.call
    }


    auto LevelUpMenu::ProcessMessage(RE::UIMessage& a_message)
        -> Result
    {
        using Message = RE::UI_MESSAGE_TYPE;

        switch (*a_message.type) {
        case Message::kShow:
            OnMenuOpen();
            return Result::kHandled;
        case Message::kHide:
            OnMenuClose();
            return Result::kHandled;
        default:
            return Base::ProcessMessage(a_message);
        }
    }


    void LevelUpMenu::Open()
    {
        auto uiQueue = RE::UIMessageQueue::GetSingleton();
        // Hide vanilla
        uiQueue->AddMessage(RE::LevelUpMenu::MENU_NAME, RE::UI_MESSAGE_TYPE::kHide, 0);

        // Show This
        uiQueue->AddMessage(Name(), RE::UI_MESSAGE_TYPE::kShow, 0);
    }


    void LevelUpMenu::Close()
    {
        auto uiQueue = RE::UIMessageQueue::GetSingleton();
        uiQueue->AddMessage(Name(), RE::UI_MESSAGE_TYPE::kHide, 0);
    }


    void LevelUpMenu::Register()
    {
        auto ui = RE::UI::GetSingleton();
        auto it = ui->menuMap.find(Name());
        if (it != ui->menuMap.end()) {
            it->second.create = Create;
        } else {
            ui->Register(Name(), Create);
        }

        logger::info("Registered {}"sv, Name().data());
    }


    RE::IMenu* LevelUpMenu::Create()
    {
        return new LevelUpMenu();
    }

    void LevelUpMenu::CloseMenu([[maybe_unused]] const RE::FxDelegateArgs& a_params)
    {
        assert(a_params.GetArgCount() == 0);

        Close();
    }

    void LevelUpMenu::Log(const RE::FxDelegateArgs& a_params)
    {
        assert(a_params.GetArgCount() == 1);
        assert(a_params[0].IsString());

        logger::info("{}: {}"sv, Name().data(), a_params[0].GetString());
    }


    void LevelUpMenu::PlaySound(const RE::FxDelegateArgs& a_params)
    {
        assert(a_params.GetArgCount() == 1);
        assert(a_params[0].IsString());

        RE::PlaySound(a_params[0].GetString());
    }


    void LevelUpMenu::OnMenuOpen()
    {
        uiMovie->SetVisible(true);
    }


    void LevelUpMenu::OnMenuClose()
    {
        RE::GFxValue boolean(false);
        uiMovie->Invoke("Selection.captureFocus", 0, &boolean, 1);
    }


    void LevelUpMenu::InitExtensions()
    {
        RE::GFxValue boolean(true);
        bool         success;

        auto input = RE::BSInputDeviceManager::GetSingleton();
        if (input->IsGamepadEnabled()) {
            uiMovie->Invoke("Selection.captureFocus", 0, &boolean, 1);
        }

        success = uiMovie->SetVariable("_global.gfxExtensions", boolean);
        assert(success);
        success = uiMovie->SetVariable("_global.noInvisibleAdvance", boolean);
        assert(success);
        success = uiMovie->SetVariable("Selection.alwaysEnableArrowKeys", boolean);
        assert(success);
        success = uiMovie->SetVariable("Selection.alwaysEnableKeyboardPress", boolean);
        assert(success);
        success = uiMovie->SetVariable("Selection.disableFocusAutoRelease", boolean);
        assert(success);
    }
}
