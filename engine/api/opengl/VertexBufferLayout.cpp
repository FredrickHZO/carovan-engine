#include <glad/glad.h>

#include "VertexBufferLayout.h"
#include "../../utils/Assertion.h"

namespace Carovan
{
    unsigned int VertexBufferElement::GetTypeSize(unsigned int type)
    {
        int size;
        switch (type)
        {
            case GL_FLOAT:
            case GL_UNSIGNED_INT:   size = 4; break;
            case GL_UNSIGNED_BYTE:  size = 1; break;
            default:                size = -1;
        }

        CAROVAN_ASSERT(size == -1, "Type is not supported");
        return size;
    }
};
