#include "MySkseLibraryExample/MyDemoSingletonImpl.h"

namespace MySkseLibraryExample {
    MyDemoSingleton& GetDemoSingleton() {
        return MyDemoSingletonImpl::GetSingleton();
    }
}
