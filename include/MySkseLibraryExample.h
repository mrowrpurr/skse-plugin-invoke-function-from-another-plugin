#pragma once

#include "MySkseLibraryExample/MyDemoSingleton.h"

namespace MySkseLibraryExample {
    extern "C" API_INTERFACE MyDemoSingleton& GetDemoSingleton();
}
