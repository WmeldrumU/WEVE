#include "weve_pipeline.hpp"


namespace weve {

        WevePipeline::WevePipeline(
        WeveDevice& device,
        const std::string& vertFilePath, 
        const std::string& fragFilepath, 
        const PipelineConfigInfo& configInfo) : weveDevice{device} {
            createGraphicsPipeline(vertFilePath, fragFilepath, configInfo);
            
        }

        std::vector<char> WevePipeline::readFile(const std::string& filepath) {
            //read in the file as a binary, star at the end (ate)
            std::ifstream file(filepath, std::ios::ate | std::ios::binary);

            if (!file.is_open()) {
                throw std::runtime_error("failed to open file: " + filepath);
            }

            //get size of file, since it is already at the end of file
            size_t fileSize = static_cast<size_t>(file.tellg());
            std::vector<char> buffer(fileSize);

            //go to beginning of file
            file.seekg(0);
            file.read(buffer.data(), fileSize);

            file.close();
            return buffer;
        }
        
        void WevePipeline::createGraphicsPipeline(const std::string& vertFilepath, const std::string& fragFilepath, const PipelineConfigInfo& configInfo) {
            auto vertCode = readFile(vertFilepath);
            auto fragCode = readFile(fragFilepath);
            
            std::cout << "Vertex Shader Code Size: " << vertCode.size() << '\n';
            std::cout << "Vertex Shader Code Size: " << fragCode.size() << '\n'; 
        }

        void WevePipeline::createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule) {
            VkShaderModuleCreateInfo createInfo{};
            createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
            createInfo.codeSize = code.size();
            createInfo.pCode = reinterpret_cast<const uint32_t*>(code.data());

            if (vkCreateShaderModule(weveDevice.device(), &createInfo, nullptr, shaderModule ) != VK_SUCCESS) {
                throw std::runtime_error("failed to create shader module!");
            }
        }

        PipelineConfigInfo WevePipeline::defaultPipelineConfigInfo(uint32_t width, uint32_t height) {
            PipelineConfigInfo configInfo{};

            configInfo.inputAssemblyInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO;
            configInfo.inputAssemblyInfo.topology = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;
            configInfo.inputAssemblyInfo.primitiveRestartEnable = VK_FALSE;
            return configInfo;
        }
}