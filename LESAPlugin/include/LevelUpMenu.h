#pragma once

#include "RE/Skyrim.h"


namespace Scaleform
{
    class LevelUpMenu : public RE::IMenu
    {
    public:
        using Base = RE::IMenu;
        using Result = RE::UI_MESSAGE_RESULTS;

        LevelUpMenu();
        virtual ~LevelUpMenu() = default;

        // IMenu
        virtual void   Accept(RE::FxDelegateHandler::CallbackProcessor* a_cbReg) override;
        virtual Result ProcessMessage(RE::UIMessage& a_message) override;

        static void Open();
        static void Close();

        static constexpr std::string_view Name();

        static void       Register();
        static RE::IMenu* Create();

    private:
        static void CloseMenu(const RE::FxDelegateArgs& a_params);
        static void Log(const RE::FxDelegateArgs& a_params);
        static void PlaySound(const RE::FxDelegateArgs& a_params);
        static void AdvanceLevel([[maybe_unused]] const RE::FxDelegateArgs& a_params);
        static void GetPlayerLevel(const RE::FxDelegateArgs& a_params);

        void OnMenuOpen();
        void OnMenuClose();

        void InitExtensions();

        static constexpr char SWF_NAME[] = "LevelUpMenuEx";

        RE::GFxValue _root;
    };


    constexpr std::string_view LevelUpMenu::Name()
    {
        return "LevelUpMenuEx";
    }
}
