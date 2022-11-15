#pragma once

#include "MySkseLibraryExample/MyDemoSingleton.h"

namespace MySkseLibraryExample {
    extern "C" MyDemoSingleton& GetDemoSingleton();
}
