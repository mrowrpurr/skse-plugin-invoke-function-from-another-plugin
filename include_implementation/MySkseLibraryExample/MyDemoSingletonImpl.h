#pragma once

#include "MySkseLibraryExample/MyDemoSingleton.h"

namespace MySkseLibraryExample {

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
        void Add(const char* value) override { items.emplace_back(value); }
        const char* GetAt(int index) override {
            if (items.size() > index)
                return items[index].c_str();
            else
                return nullptr;
        }
        void LogAll() override {
            logger::info("LogAll ({})", items.size());
            for (auto& text : items) {
                logger::info("ITEM: {}", text);
            }
        }
    };
}
