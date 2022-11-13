#pragma once

#include "SkseLibraryDemo/Implementation/MyDemoSingletonImpl.h"

namespace SkseLibraryDemo {
    MyDemoSingleton& GetDemoSingleton() {
        return MyDemoSingletonImpl::GetSingleton();
    }
}
