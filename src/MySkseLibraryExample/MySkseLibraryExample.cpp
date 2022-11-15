#include "MySkseLibraryExample/MyDemoSingletonImpl.h"

namespace MySkseLibraryExample {
    int BasicTest() { return 69; }

    extern "C" MyDemoSingleton& GetDemoSingleton() {
        return MyDemoSingletonImpl::GetSingleton();
    }
}
