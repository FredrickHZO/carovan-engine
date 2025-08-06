#include <glad/glad.h>

#include "VertexArray.h"
#include "Common.h"

namespace Carovan
{
    VertexArray::VertexArray()
    {
        GL_FUNCTION(glGenVertexArrays(1, &m_RendererID));
    }

    VertexArray::~VertexArray()
    {
        GL_FUNCTION(glDeleteVertexArrays(1, &m_RendererID));
    }

    VertexArray::VertexArray(VertexArray&& other) noexcept
        : m_RendererID(other.m_RendererID)
    {
        other.m_RendererID = 0;
    }

    VertexArray& VertexArray::operator=(VertexArray&& other) noexcept
    {
        if (this != &other)
        {
            GL_FUNCTION(glDeleteVertexArrays(1, &m_RendererID));
            m_RendererID = other.m_RendererID;
            other.m_RendererID = 0;
        }
        return *this;
    }


    void VertexArray::AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout) const
    {
        Bind();
        vb.Bind();
        const auto& elements = layout.GetElements();
        unsigned int offset = 0;
        for (unsigned int i = 0; i < elements.size(); i++)
        {
            const auto& element = elements[i];
            GL_FUNCTION(glEnableVertexAttribArray(i));
            GL_FUNCTION(glVertexAttribPointer(i, element.count, element.type,
                    element.normalized, layout.GetStride(), reinterpret_cast<void*>(offset)));

            offset += element.count * VertexBufferElement::GetTypeSize(element.type);
        }
    }

    void VertexArray::Bind() const
    {
        GL_FUNCTION(glBindVertexArray(m_RendererID));
    }

    void VertexArray::Unbind() const
    {
        GL_FUNCTION(glBindVertexArray(0));
    }
};
