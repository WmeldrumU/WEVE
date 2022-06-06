#pragma once
#include "weve_device.hpp"

// libs
#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE // forces depth buffer values to be [0, 1.0] -- OpenGL does [-1, 1]
#include <glm/glm.hpp>

// std
#include <vector>

namespace weve
{
    /**
     * @brief This class is used for allocating memory for
     * vertex data and copy it over to gpu. Needs device reference
     * because of this.
     *
     */
    class WeveModel
    {
    public:
        struct Vertex
        {
            glm::vec2 position;

            static std::vector<VkVertexInputBindingDescription> getBindingDescriptions();
            static std::vector<VkVertexInputAttributeDescription> getAttributeDescriptions();
        };

        WeveModel(WeveDevice &device, const std::vector<Vertex> &vertices);
        ~WeveModel();
        WeveModel(const WeveModel &) = delete;
        WeveModel &operator=(const WeveModel &) = delete;

        void bind(VkCommandBuffer commandBuffer);
        void draw(VkCommandBuffer commandBuffer);

    private:
        void createVertexBuffers(const std::vector<Vertex> &vertices);

        WeveDevice &weveDevice;
        VkBuffer vertexBuffer; //this is RAM
        VkDeviceMemory vertexBufferMemory; //this is GPU memory
        uint32_t vertexCount;
    };
}