#pragma once

#include "MySkseLibraryExample/MyDemoSingleton.h"

namespace MySkseLibraryExample {

    class MyDemoSingletonImpl : public MyDemoSingleton {
        MyDemoSingletonImpl() = default;
        std::vector<std::string> items = {};

    public:
        MyDemoSingletonImpl(const MyDemoSingletonImpl&) = delete;
        MyDemoSingletonImpl &operator=(const MyDemoSingletonImpl&) = delete;
        static API_INTERFACE MyDemoSingleton& GetSingleton();

        API_INTERFACE size_t GetCount() override { return items.size(); }
        API_INTERFACE void Clear() override { items.clear(); }
        API_INTERFACE void Add(const char* value) override { items.emplace_back(value); }
        API_INTERFACE const char* GetAt(int index) override {
            if (items.size() > index)
                return items[index].c_str();
            else
                return nullptr;
        }
        API_INTERFACE void LogAll() override {
            logger::info("LogAll ({})", items.size());
            for (auto& text : items) {
                logger::info("ITEM: {}", text);
            }
        }
    };
}
