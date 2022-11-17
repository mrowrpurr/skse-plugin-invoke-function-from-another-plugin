namespace stl {
	constexpr std::string_view safe_string(const char* a_str) { return a_str ? a_str : ""sv; }
}

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

 SKSE::GetMessagingInterface()->RegisterListener("MySkseLibrary.ClientTwo", [](SKSE::MessagingInterface::Message* event){
            logger::info("MESSAGE FROM THE client!");
        });

            logger::info("Message Type {}", event->type);
            if (event->type == SKSE::MessagingInterface::kDataLoaded) {
                logger::info("Hello From Skse Library API");
                auto* api = &MySkseLibraryExample::GetDemoSingleton();
                logger::info("Sending 6969");
                SKSE::GetMessagingInterface()->Dispatch(6969, api, sizeof(api), "MySkseLibrary.ClientTwo");
            } else if (event->type == 6969) {
                logger::info("GOT 6969 from server");
            }
        });
        return true;
    }
}
