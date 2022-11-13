#pragma once

namespace MySkseLibraryExample {

    class __declspec(dllexport) MyDemoSingleton {
    public:
        virtual size_t GetCount() = 0;
        virtual void Clear() = 0;
        virtual void Add(char* value) = 0;
        virtual const char* GetAt(int index) = 0;
    };
}
