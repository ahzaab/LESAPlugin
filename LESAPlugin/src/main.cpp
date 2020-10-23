#include "PCH.h"

#include <memory>

#include "Events.h"
#include "Scaleform.h"
#include "version.h"
#include "AHZConsole.h"

// TODO

#include "RE/Skyrim.h"
#include "SKSE/API.h"


// Just initialize to start routing to the console window
Debug::CAHZDebugConsole theDebugConsole;

namespace
{
    void MessageHandler(SKSE::MessagingInterface::Message* a_msg)
    {
        switch (a_msg->type) {
        case SKSE::MessagingInterface::kDataLoaded:
        {
            Events::Install();
            Scaleform::RegisterCreators();
        } break;
        }
    }
}

extern "C"
{
    auto SKSEPlugin_Query(const SKSE::QueryInterface* a_skse, SKSE::PluginInfo* a_info) -> bool
    {
        try {
#ifndef NDEBUG
            auto                    msvc_sink = std::make_shared<spdlog::sinks::msvc_sink_mt>();
            auto                    console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
            spdlog::sinks_init_list sink_list = { msvc_sink, console_sink };
            auto                    log = std::make_shared<spdlog::logger>("multi_sink", sink_list.begin(), sink_list.end());
            log->set_level(spdlog::level::trace);
            spdlog::flush_every(std::chrono::seconds(3));
            spdlog::register_logger(log);
#else
            auto path = logger::log_directory();
            if (!path) {
                return false;
            }

            *path /= "LESAPlugin.log"sv;

            auto sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(path->string(), true);
            auto log = std::make_shared<spdlog::logger>("global log"s, std::move(sink));
            log->set_level(spdlog::level::info);
            log->flush_on(spdlog::level::warn);
            spdlog::flush_every(std::chrono::seconds(3));
#endif

            spdlog::set_default_logger(std::move(log));
            spdlog::set_pattern("%g(%#): [%l] %v");

            logger::info("LESA Plugin v{}"sv, LESA_VERSION_VERSTRING);

            a_info->infoVersion = SKSE::PluginInfo::kVersion;
            a_info->name = "LESAPlugin";
            a_info->version = LESA_VERSION_MAJOR;

            if (a_skse->IsEditor()) {
                logger::critical("Loaded in editor, marking as incompatible!"sv);
                return false;
            }

            const auto ver = a_skse->RuntimeVersion();
            if (ver <= SKSE::RUNTIME_1_5_39) {
                logger::critical("Unsupported runtime version {}!"sv, ver.string().c_str());
                return false;
            }

        } catch (const std::exception& e) {
            logger::critical(e.what());
            return false;
        } catch (...) {
            logger::critical("caught unknown exception"sv);
            return false;
        }

        return true;
    }

    auto SKSEPlugin_Load(const SKSE::LoadInterface* a_skse) -> bool
    {
        try {
            logger::info("LESA Plugin loading"sv);

            SKSE::Init(a_skse);

            // Only needed for hooks
            //SKSE::AllocTrampoline(1 << 4);

            auto messaging = SKSE::GetMessagingInterface();
            if (!messaging->RegisterListener("SKSE", MessageHandler)) {
                logger::critical("Could not register MessageHandler"sv);
                return false;
            }
            logger::info("registered listener"sv);


            logger::info("Registering Callbacks"sv);
            Scaleform::RegisterCallbacks();

            logger::info("LESA Plugin loaded"sv);

        } catch (const std::exception& e) {
            logger::critical(e.what());
            return false;
        } catch (...) {
            logger::critical("caught unknown exception"sv);
            return false;
        }

        return true;
    }
};
