#include "PluginWithFunction.h"

const char* PluginWithFunction::SayHello() {
    SKSE::log::info("SayHello() called");
    return "Hello!";
}
