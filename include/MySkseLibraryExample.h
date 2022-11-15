#pragma once

#include "MySkseLibraryExample/MyDemoSingleton.h"

namespace MySkseLibraryExample {
    API_INTERFACE int BasicTest();
    extern "C" API_INTERFACE MyDemoSingleton& GetDemoSingleton();
}
