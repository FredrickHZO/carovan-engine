#include <glad/glad.h>

#include "Common.h"
#include "IndexBuffer.h"
#include "../../utils/Assertion.h"

namespace Carovan
{
    IndexBuffer::IndexBuffer(const unsigned int* data, const unsigned int count)
         : m_RendererID(0), m_Count(count)
    {
        constexpr bool sameSize = sizeof(unsigned int) != sizeof(GLuint);
        CAROVAN_ASSERT(sameSize, "GLuint is not the size of unsigned int");

        GL_FUNCTION(glGenBuffers(1, &m_RendererID));
        GL_FUNCTION(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID));
        GL_FUNCTION(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW));
    }

    IndexBuffer::IndexBuffer(IndexBuffer&& other) noexcept
        : m_RendererID(other.m_RendererID), m_Count(other.m_Count)
    {
        other.m_RendererID = 0;
        other.m_Count = 0;
    }

    IndexBuffer& IndexBuffer::operator=(IndexBuffer&& other) noexcept
    {
        if (this != &other)
        {
            GL_FUNCTION(glDeleteBuffers(1, &m_RendererID));
            this->m_RendererID = other.m_RendererID;
            this->m_Count = other.m_Count;
            other.m_RendererID = 0;
            other.m_Count = 0;
        }
        return *this;
    }

    IndexBuffer::~IndexBuffer()
    {
        GL_FUNCTION(glDeleteBuffers(1, &m_RendererID));
    }

    void IndexBuffer::Bind() const
    {
        GL_FUNCTION(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID));
    }

    void IndexBuffer::Unbind() const
    {
        GL_FUNCTION(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
    }
};
