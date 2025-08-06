add_subdirectory(glfw)
add_subdirectory(spdlog)

add_library(glm INTERFACE)
target_include_directories(glm INTERFACE glm/include)

add_library(entt_static INTERFACE)
target_include_directories(entt_static INTERFACE entt/single_include)

add_library(glad_static STATIC glad/src/glad.c)
target_include_directories(glad_static PUBLIC glad/include)

file(GLOB_RECURSE IMGUI_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/imgui/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/imgui/*.h
)
add_library(imgui_static STATIC ${IMGUI_SOURCES})
target_include_directories(imgui_static PUBLIC
        imgui
        imgui/backends
)
target_link_libraries(imgui_static PUBLIC glfw glad_static)

add_library(Carovan_dependencies INTERFACE)
target_link_libraries(Carovan_dependencies INTERFACE
        glfw
        spdlog::spdlog
        glm
        entt_static
        glad_static
        imgui_static
)
