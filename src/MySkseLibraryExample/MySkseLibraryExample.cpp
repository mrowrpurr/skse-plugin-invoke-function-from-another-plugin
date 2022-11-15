#include "MySkseLibraryExample/MyDemoSingletonImpl.h"

namespace MySkseLibraryExample {
    extern "C" int BasicTest() { return 69; }

    extern "C" MyDemoSingleton& GetDemoSingleton() {
        return MyDemoSingletonImpl::GetSingleton();
    }
}
