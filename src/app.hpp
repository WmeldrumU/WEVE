#pragma once

#include "weve_window.hpp"
#include "weve_pipeline.hpp"
#include "weve_device.hpp"

namespace weve {
    class App {
        public:
        static constexpr int WIDTH = 1080;
        static constexpr int HEIGHT = 720;

        void run();

        private:
        WeveWindow weveWindow{WIDTH, HEIGHT, "Hello Vulkan!"};
        WeveDevice weveDevice{weveWindow};
        WevePipeline wevePipeline{
            weveDevice, 
        "./shaders/shader.vert.spv", 
        "./shaders/shader.frag.spv", 
        WevePipeline::defaultPipelineConfigInfo(WIDTH, HEIGHT)
        };
    };
}