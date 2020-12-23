#pragma once
#include "RE/Skyrim.h"

namespace Scaleform
{
    class LevelUpMenuHook : public RE::LevelUpMenu
    {
    public:
        static void InstallHooks();

    private:
        using Result = RE::UI_MESSAGE_RESULTS;

        static void CloseMenu([[maybe_unused]] const RE::FxDelegateArgs& a_params);
        static void Close();

        void   Hook_Accept(RE::FxDelegateHandler::CallbackProcessor* a_cbReg);
        Result Hook_ProcessMessage(RE::UIMessage& a_message);

        using Accept_t = decltype(&RE::LevelUpMenu::Accept);
        using ProcessMessage_t = decltype(&RE::LevelUpMenu::ProcessMessage);

        static inline REL::Relocation<Accept_t>         _Accept;
        static inline REL::Relocation<ProcessMessage_t> _ProcessMessage;
    };
}
