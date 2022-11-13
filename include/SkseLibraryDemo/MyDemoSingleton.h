#pragma once

namespace SkseLibraryDemo {

    class MyDemoSingleton {
        MyDemoSingleton() = default;

    public:
        MyDemoSingleton(const MyDemoSingleton&) = delete;
        MyDemoSingleton &operator=(const MyDemoSingleton&) = delete;
        static MyDemoSingleton& GetSingleton() {
            static MyDemoSingleton demo;
            return demo;
        }

        std::vector<std::string> someStrings = {};
    };
}
