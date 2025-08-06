#pragma once

#include <string>
#include <stdexcept>

#pragma warning(push, 0)
    #define CAROVAN_ASSERT(x, s)                        \
    do {                                                \
        bool err = x;                                   \
        std::string str = s;                            \
        if (err)                                        \
        {                                               \
            std::string errstr = "Error: " + str;       \
            errstr += "\n\n";                           \
            throw std::runtime_error(errstr);           \
        }                                               \
    } while (0)
#pragma warning(pop)