#include "MySkseLibraryExample.h"

namespace MySkseLibraryExample::Implementation {

    void InitializeLog() {
        auto path = logger::log_directory();
        *path /= fmt::format("{}.log", SKSE::PluginDeclaration::GetSingleton()->GetName());
        auto sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(path->string(), true);
        const auto level = spdlog::level::trace;
        auto log = std::make_shared<spdlog::logger>("global log"s, std::move(sink));
        log->set_level(level);
        log->flush_on(level);
        spdlog::set_default_logger(std::move(log));
        spdlog::set_pattern("%g(%#): [%^%l%$] %v"s);
    }

    SKSEPluginLoad(const SKSE::LoadInterface* skse) {
        InitializeLog();
        logger::info("Initialize");
        SKSE::Init(skse);
        SKSE::GetMessagingInterface()->RegisterListener([](SKSE::MessagingInterface::Message* event){
            if (event->type == SKSE::MessagingInterface::kDataLoaded) {
                logger::info("Hello From Skse Library API");
                // SKSE::GetPapyrusInterface()->Register(PapyrusInterface::BIND);
            }
        });
        return true;
    }
}
