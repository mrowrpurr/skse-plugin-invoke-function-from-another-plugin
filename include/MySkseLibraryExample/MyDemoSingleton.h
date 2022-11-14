#pragma once

namespace MySkseLibraryExample {

    class API_INTERFACE MyDemoSingleton {
    public:
        virtual size_t GetCount() = 0;
        virtual void Clear() = 0;
        virtual void Add(const char* value) = 0;
        virtual const char* GetAt(int index) = 0;
        virtual void LogAll() = 0;
    };
}
