#pragma once

#include "../../utils/assertion.h"

#ifdef _NDEBUG
    #define GL_FUNCTION(x) x
#else
    #define GL_FUNCTION(x)                                    \
        GLClearError();                                       \
        x;                                                    \
        CAROVAN_ASSERT(GLCheckError(#x, __FILE__, __LINE__),  \
        "OpenGL function returned an error");
#endif

namespace Carovan
{
    void GLClearError();
    bool GLCheckError(const char* function, const char* file, int line);
};
