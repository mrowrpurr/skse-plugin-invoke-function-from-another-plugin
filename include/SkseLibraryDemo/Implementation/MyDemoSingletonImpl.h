#pragma once

#include "SkseLibraryDemo/MyDemoSingleton.h"

namespace SkseLibraryDemo {

    class MyDemoSingletonImpl : public MyDemoSingleton {
        MyDemoSingletonImpl() = default;
        std::vector<std::string> items = {};

    public:
        MyDemoSingletonImpl(const MyDemoSingletonImpl&) = delete;
        MyDemoSingletonImpl &operator=(const MyDemoSingletonImpl&) = delete;
        static MyDemoSingletonImpl& GetSingleton() {
            static MyDemoSingletonImpl demo;
            return demo;
        }

        size_t GetCount() override { return items.size(); }
        void Clear() override { items.clear(); }
        void Add(char* value) override { items.emplace_back(value); }
        const char* GetAt(int index) override {
            if (items.size() > index)
                return items[index].c_str();
            else
                return nullptr;
        }


    };
}
