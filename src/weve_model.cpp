#include "weve_model.hpp"

// std
#include <cassert>
#include <cstring>

namespace weve {
    WeveModel::WeveModel(WeveDevice &device, const std::vector<Vertex> &vertices) : weveDevice{device} {
        createVertexBuffers(vertices);
    }

    WeveModel::~WeveModel() {
        vkDestroyBuffer(weveDevice.device(), vertexBuffer, nullptr);
        vkFreeMemory(weveDevice.device(), vertexBufferMemory, nullptr);
    }

    void WeveModel::createVertexBuffers(const std::vector<Vertex> &vertices) {
        vertexCount = static_cast<uint32_t>(vertices.size());
        assert(vertexCount >= 3 && "Vertex count must be at least 3");
        VkDeviceSize bufferSize = sizeof(vertices[0]) * vertexCount;

        weveDevice.createBuffer(bufferSize, 
        VK_BUFFER_USAGE_VERTEX_BUFFER_BIT,
        VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, //host visible tells vulkan we want the memory to be visible from our host aka cpu
                                                //host coherent keeps device and host memory regions consistent with each other
        vertexBuffer,
        vertexBufferMemory);


        void *data;
        vkMapMemory(weveDevice.device(), vertexBufferMemory, 0, bufferSize, 0, &data );
        memcpy(data, vertices.data(), static_cast<size_t>(bufferSize)); // takes vertex data, sends it into host-mapped memory, because of the host coherent bit,
        //host memory will automatically be flushed to update device memory, would need to call flush() otherwise
        vkUnmapMemory(weveDevice.device(), vertexBufferMemory);
    }   

    void WeveModel::draw(VkCommandBuffer commandBuffer) {
        vkCmdDraw(commandBuffer, vertexCount, 1, 0, 0);
    }

    void WeveModel::bind(VkCommandBuffer commandBuffer) {
        VkBuffer buffers[] = {vertexBuffer};
        VkDeviceSize offsets[] = {0};
        vkCmdBindVertexBuffers(commandBuffer, 0, 1, buffers, offsets);
    }

    std::vector<VkVertexInputBindingDescription> WeveModel::Vertex::getBindingDescriptions() {
        std::vector<VkVertexInputBindingDescription> bindingDescriptions(1);
        bindingDescriptions[0].binding = 0;
        bindingDescriptions[0].stride = sizeof(Vertex);
        bindingDescriptions[0].inputRate = VK_VERTEX_INPUT_RATE_VERTEX;
        return bindingDescriptions;
    }

    std::vector<VkVertexInputAttributeDescription> WeveModel::Vertex::getAttributeDescriptions() {
        std::vector<VkVertexInputAttributeDescription> attributeDescriptions(1);

        attributeDescriptions[0].binding = 0;
        attributeDescriptions[0].location = 0;
        attributeDescriptions[0].format = VK_FORMAT_R32G32_SFLOAT;
        attributeDescriptions[0].offset = 0;

        return attributeDescriptions;
    }
} // namespace weve