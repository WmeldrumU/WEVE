#pragma once

#include "weve_window.hpp"

namespace weve {
    class App {
        public:
        static constexpr int WIDTH = 1080;
        static constexpr int HEIGHT = 720;

        void run();

        private:
        WeveWindow weveWindow{WIDTH, HEIGHT, "Hello Vulkan!"};
    };
}