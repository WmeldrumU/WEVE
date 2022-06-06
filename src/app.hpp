#pragma once

#include "weve_window.hpp"
#include "weve_pipeline.hpp"
#include "weve_device.hpp"
#include "weve_swap_chain.hpp"
#include "weve_model.hpp"

// std
#include <memory>
#include <vector>

namespace weve
{
    class App
    {
    public:
        static constexpr int WIDTH = 1080;
        static constexpr int HEIGHT = 720;

        App();
        ~App();

        App(const App &) = delete;
        App &operator=(const App &) = delete;

        void run();

    private:
        void loadModels();
        void createPipelineLayout();
        void createPipeline();
        void createCommandBuffers();
        void drawFrame();

        WeveWindow weveWindow{WIDTH, HEIGHT, "Hello Vulkan!"};
        WeveDevice weveDevice{weveWindow};
        WeveSwapChain weveSwapChain{weveDevice, weveWindow.getExtent()};
        std::unique_ptr<WevePipeline> wevePipeline;
        VkPipelineLayout pipelineLayout;
        std::vector<VkCommandBuffer> commandBuffers;
        std::unique_ptr<WeveModel> weveModel;
    };
}