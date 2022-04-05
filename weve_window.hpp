#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <string>

namespace weve {
    class WeveWindow {
        public:
        WeveWindow(int w, int h, std::string name);
        ~WeveWindow();

        private:
        void initWindow();
        

        const int width;
        const int height;

        std::string windowName;
        GLFWwindow *window;
    };
}