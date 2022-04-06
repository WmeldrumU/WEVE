#include "app.hpp"

namespace weve {
    void App::run() {
        while (!weveWindow.shouldClose()) {
            glfwPollEvents();
        }
    }
}