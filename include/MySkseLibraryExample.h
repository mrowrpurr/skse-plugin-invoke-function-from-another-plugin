#pragma once

#include "MySkseLibraryExample/Implementation/MyDemoSingletonImpl.h"

namespace MySkseLibraryExample {
    extern "C" __declspec(dllexport) MyDemoSingleton& GetDemoSingleton() {
        return MyDemoSingletonImpl::GetSingleton();
    }
}
