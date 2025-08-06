#include <glad/glad.h>

#include "VertexBuffer.h"
#include "Common.h"

namespace Carovan
{
    VertexBuffer::VertexBuffer(const void* data, const unsigned int size)
    {
        GL_FUNCTION(glGenBuffers(1, &this->m_RenderID));
        GL_FUNCTION(glBindBuffer(GL_ARRAY_BUFFER, this->m_RenderID));
        GL_FUNCTION(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
    }

    VertexBuffer::~VertexBuffer()
    {
        GL_FUNCTION(glDeleteBuffers(1, &this->m_RenderID));
    }

    void VertexBuffer::Bind() const
    {
        GL_FUNCTION(glBindBuffer(GL_ARRAY_BUFFER, this->m_RenderID));
    }

    void VertexBuffer::Unbind() const
    {
        GL_FUNCTION(glBindBuffer(GL_ARRAY_BUFFER, 0));
    }
};
