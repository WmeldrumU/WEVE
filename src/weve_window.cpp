#include "weve_window.hpp"

namespace weve {
    WeveWindow::WeveWindow(int w, int h, std::string name) : width{w}, height{h}, windowName{name} {
        initWindow();
    }

    WeveWindow::~WeveWindow() {
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    void WeveWindow::initWindow() {
        glfwInit();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
    }
}