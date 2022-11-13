#pragma once

#include "MySkseLibraryExample/Implementation/MyDemoSingletonImpl.h"

namespace MySkseLibraryExample {
    MyDemoSingleton& GetDemoSingleton() {
        return MyDemoSingletonImpl::GetSingleton();
    }
}
