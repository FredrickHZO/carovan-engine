#pragma once

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

namespace Carovan
{
    class VertexArray
    {
    private:
        unsigned int m_RendererID;

    public:
        VertexArray();
        ~VertexArray();

        VertexArray(const VertexArray&) = delete;
        VertexArray& operator=(const VertexArray&) = delete;

        VertexArray(VertexArray&& other) noexcept;
        VertexArray& operator=(VertexArray&& other) noexcept;

        void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout) const;
        void Bind() const;
        void Unbind() const;
    };
};
