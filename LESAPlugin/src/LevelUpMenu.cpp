#include "PCH.h"
#include "LevelUpMenu.h"

namespace Scaleform
{
    namespace LevelUpMenu
    {
        constexpr REL::ID Vtbl(static_cast<std::uint64_t>(269130));
    }

    void LevelUpMenuHook::Hook_Accept(RE::FxDelegateHandler::CallbackProcessor* a_cbReg)
    {
        _Accept(this, a_cbReg);
        // Override
        a_cbReg->Process("addHealth", CloseMenu);

        // New
        a_cbReg->Process("CloseMenu", CloseMenu);
    }

    auto LevelUpMenuHook::Hook_ProcessMessage(RE::UIMessage& a_message)
        -> Result
    {
        return _ProcessMessage(this, a_message);
    }

    void LevelUpMenuHook::CloseMenu([[maybe_unused]] const RE::FxDelegateArgs& a_params)
    {
        assert(a_params.GetArgCount() == 0);

        Close();
    }

    void LevelUpMenuHook::Close()
    {
        // Must advance the players level so the level up menu does not get stuck in a loop
        auto player = RE::PlayerCharacter::GetSingleton();
        player->skills->AdvanceLevel(false);

        auto uiQueue = RE::UIMessageQueue::GetSingleton();
        uiQueue->AddMessage(LevelUpMenu::MENU_NAME, RE::UI_MESSAGE_TYPE::kHide, 0);
    }

    void LevelUpMenuHook::InstallHooks()
    {
        // Hook into Accept and Process
        REL::Relocation<std::uintptr_t> vTable(Scaleform::LevelUpMenu::Vtbl);
        _Accept = vTable.write_vfunc(0x1, &LevelUpMenuHook::Hook_Accept);
        _ProcessMessage = vTable.write_vfunc(0x4, &LevelUpMenuHook::Hook_ProcessMessage);
        logger::info("Installed hooks");
    }
}
