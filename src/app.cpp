#include "app.hpp"

namespace weve {

    App::App() {
        createPipelineLayout();
        createPipeline();
        createCommandBuffers();

    }

    App::~App() {
        vkDestroyPipelineLayout(weveDevice.device(), pipelineLayout, nullptr);
    }

    void App::run() {
        while (!weveWindow.shouldClose()) {
            glfwPollEvents();
        }
    }

    void App::createPipelineLayout() {
        VkPipelineLayoutCreateInfo pipelineLayoutInfo{};
        pipelineLayoutInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
        pipelineLayoutInfo.setLayoutCount = 0;
        pipelineLayoutInfo.pSetLayouts = nullptr;
        pipelineLayoutInfo.pushConstantRangeCount = 0;
        pipelineLayoutInfo.pPushConstantRanges = nullptr;
        if (vkCreatePipelineLayout(weveDevice.device(), &pipelineLayoutInfo, nullptr,
        &pipelineLayout) != VK_SUCCESS) {
            throw std::runtime_error("failed to create pipeline layout!");
        }
    }

    void App::createPipeline() {
        auto pipelineConfig = WevePipeline::defaultPipelineConfigInfo(weveSwapChain.width(), 
                                                                    weveSwapChain.height());
        pipelineConfig.renderPass = weveSwapChain.getRenderPass();
        pipelineConfig.pipelineLayout = pipelineLayout;
        wevePipeline = std::make_unique<WevePipeline>(
            weveDevice,
            "shaders/shader.vert.spv",
            "shaders/shader.frag.spv",
            pipelineConfig
        );
    }

    void App::createCommandBuffers() {

    }

    void App::drawFrame() {
        
    }
}