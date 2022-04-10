#include "weve_window.hpp"

#include <stdexcept>

namespace weve {
    WeveWindow::WeveWindow(int w, int h, std::string name) : width{w}, height{h}, windowName{name} {
        initWindow();
    }

    WeveWindow::~WeveWindow() {
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    bool WeveWindow::shouldClose() { 
        return glfwWindowShouldClose(window);
    }

    void WeveWindow::initWindow() {
        glfwInit();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
    }

    void WeveWindow::createWindowSurface(VkInstance instance, VkSurfaceKHR *surface) {
        if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS) {
            throw std::runtime_error("failed to create window surface!");
        }
    }
}