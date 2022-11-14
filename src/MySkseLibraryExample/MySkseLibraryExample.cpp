#include "MySkseLibraryExample/MyDemoSingletonImpl.h"

namespace MySkseLibraryExample {
    extern "C" MyDemoSingleton& GetDemoSingleton() {
        return MyDemoSingletonImpl::GetSingleton();
    }
}
