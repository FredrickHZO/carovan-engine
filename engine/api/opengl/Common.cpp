#include "Common.h"
#include "glad/glad.h"
#include "../../core/Logger.h"

namespace Carovan
{
    void GLClearError()
    {
        while (glGetError() != GL_NO_ERROR);
    }

    bool GLCheckError(const char* function, const char* file, int line)
    {
        while (GLenum error = glGetError())
        {
            LOG_ERROR("OpenGL error {}, Function: {}, Line: {}, File: {}",
                error, function, line, file);
            return true;
        }
        return false;
    };
};
