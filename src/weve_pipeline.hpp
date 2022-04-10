#pragma once

#include "weve_device.hpp"

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

namespace weve {    

    struct PipelineConfigInfo {
        VkPipelineInputAssemblyStateCreateInfo inputAssemblyInfo;
    };

    class WevePipeline {
    public:
        WevePipeline(
        WeveDevice& device,
        const std::string& vertFilePath, 
        const std::string& fragFilepath, 
        const PipelineConfigInfo& configInfo);
        ~WevePipeline(){};

        WevePipeline(const WevePipeline&) = delete;
        void operator=(const WevePipeline&) = delete;

        static PipelineConfigInfo defaultPipelineConfigInfo(uint32_t width, uint32_t height);


    private:
        static std::vector<char> readFile(const std::string& filepath);

        void createGraphicsPipeline(
        const std::string& vertFilepath, 
        const std::string& fragFilepath, 
        const PipelineConfigInfo& configInfo);

        void createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule);

        WeveDevice& weveDevice;
        VkPipeline graphicsPipeline;
        VkShaderModule vertShaderModule;
        VkShaderModule fragShaderModule;

    };

}