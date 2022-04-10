#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <string>

namespace weve {
    class WeveWindow {
        public:
        WeveWindow(int w, int h, std::string name);
        ~WeveWindow();

        //deleting copy contrstuctor and copy operators
        WeveWindow(const WeveWindow &) = delete;
        WeveWindow &operator=(const WeveWindow &) = delete;

        bool shouldClose();

        void createWindowSurface(VkInstance instance, VkSurfaceKHR *surface);

        private:
        void initWindow();
        

        const int width;
        const int height;

        std::string windowName;
        GLFWwindow *window;
    };
}