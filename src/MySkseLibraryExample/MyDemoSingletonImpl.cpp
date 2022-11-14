#include "MySkseLibraryExample/MyDemoSingletonImpl.h"

namespace MySkseLibraryExample {
    MyDemoSingleton& MyDemoSingletonImpl::GetSingleton() {
        static MyDemoSingletonImpl demo;
        return demo;
    };
}
