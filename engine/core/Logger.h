#pragma once

#pragma warning(push, 0)
    #include "spdlog/spdlog.h"
#pragma warning(pop)

#ifdef _NDEBUG
    #define LOG_CRITICAL(...) (void)0
    #define LOG_ERROR(...)    (void)0
    #define LOG_INFO(...)     (void)0
    #define LOG_WARN(...)     (void)0
#else
    #define LOG_CRITICAL(...) spdlog::critical(__VA_ARGS__)
    #define LOG_ERROR(...)    spdlog::error(__VA_ARGS__)
    #define LOG_INFO(...)     spdlog::info(__VA_ARGS__)
    #define LOG_WARN(...)     spdlog::warn(__VA_ARGS__)
#endif

