#pragma once

#include "MySkseLibraryExample/MyDemoSingleton.h"

namespace MySkseLibraryExample {
    extern "C" DLL_EXPORTED MyDemoSingleton& GetDemoSingleton();
}
