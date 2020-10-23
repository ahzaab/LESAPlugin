#include "PCH.h"
#include "Events.h"
#include "LevelUpMenu.h"

#include <memory>

namespace Events
{
    auto MenuAndInputHander::GetSingleton() -> MenuAndInputHander*
    {
        static MenuAndInputHander singleton;
        return std::addressof(singleton);
    }

    void MenuAndInputHander::Sink()
    {
        auto input = RE::BSInputDeviceManager::GetSingleton();
        input->AddEventSink(static_cast<RE::BSTEventSink<RE::InputEvent*>*>(MenuAndInputHander::GetSingleton()));
        auto ui = RE::UI::GetSingleton();
        ui->AddEventSink(static_cast<RE::BSTEventSink<RE::MenuOpenCloseEvent>*>(MenuAndInputHander::GetSingleton()));
    }

    auto MenuAndInputHander::ProcessEvent(RE::MenuOpenCloseEvent const* a_event, [[maybe_unused]] RE::BSTEventSource<RE::MenuOpenCloseEvent>* a_eventSource) -> RE::BSEventNotifyControl
    {
        if (a_event == nullptr) {
            return RE::BSEventNotifyControl::kContinue;
        }
        if (a_event->menuName == RE::LevelUpMenu::MENU_NAME && a_event->opening) {
            Scaleform::LevelUpMenu::Open();
        }
        return RE::BSEventNotifyControl::kContinue;
    }

    auto MenuAndInputHander::ProcessEvent(RE::InputEvent* const* a_event, [[maybe_unused]] RE::BSTEventSource<RE::InputEvent*>* a_eventSource) -> RE::BSEventNotifyControl
    {
        using Device = RE::INPUT_DEVICE;
        using Input = RE::INPUT_EVENT_TYPE;
        using Key = RE::BSKeyboardDevice::Key;
        using Message = RE::UI_MESSAGE_TYPE;

        if (a_event == nullptr) {
            return RE::BSEventNotifyControl::kContinue;
        }

        auto ui = RE::UI::GetSingleton();
        for (auto event = *a_event; event; event = event->next) {
            auto button = static_cast<RE::ButtonEvent*>(event);
            if (event->eventType != Input::kButton) {
                continue;
            }
        }
        return RE::BSEventNotifyControl::kContinue;
    }

    void Install()
    {
        MenuAndInputHander::Sink();
        logger::info("Installed all event sinks");
    }
}
