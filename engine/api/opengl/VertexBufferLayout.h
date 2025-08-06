#pragma once

#include <vector>

namespace Carovan
{
    struct VertexBufferElement
    {
        unsigned int   type;
        unsigned int   count;
        unsigned char  normalized;

        static unsigned int GetTypeSize(unsigned int type);
    };

    class VertexBufferLayout
    {
    private:
        std::vector<VertexBufferElement> m_Elements;
        unsigned int m_Stride;

    public:
        VertexBufferLayout()
            :m_Stride(0) {}

        ~VertexBufferLayout() = default;

        template<typename T>
        void Push(unsigned int count) {}

        [[nodiscard]]
        inline unsigned int GetStride() const { return this->m_Stride; }
        [[nodiscard]]
        inline std::vector<VertexBufferElement> GetElements() const { return this->m_Elements; }
    };

    template<>
    inline void VertexBufferLayout::Push<float>(const unsigned int count)
    {
        this->m_Elements.push_back(VertexBufferElement{ GL_FLOAT, count, GL_FALSE });
        this->m_Stride += count * VertexBufferElement::GetTypeSize(GL_FLOAT);
    }

    template<>
    inline void VertexBufferLayout::Push<unsigned int>(const unsigned int count)
    {
        this->m_Elements.push_back(VertexBufferElement{ GL_UNSIGNED_INT, count, GL_FALSE });
        this->m_Stride += count * VertexBufferElement::GetTypeSize(GL_UNSIGNED_INT);
    }

    template<>
    inline void VertexBufferLayout::Push<unsigned char>(const unsigned int count)
    {
        this->m_Elements.push_back(VertexBufferElement{ GL_UNSIGNED_BYTE, count, GL_TRUE });
        this->m_Stride += count * VertexBufferElement::GetTypeSize(GL_UNSIGNED_BYTE);
    }
};
