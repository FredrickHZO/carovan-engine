file(GLOB_RECURSE ENGINE_SOURCES CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/*.h")

add_library(glad_static STATIC lib/glad/src/glad.c)
target_include_directories(glad_static PUBLIC lib/glad/include)

file(GLOB IMGUI_SOURCES
        lib/imgui/*.cpp
        lib/imgui/backends/imgui_impl_glfw.cpp
        lib/imgui/backends/imgui_impl_opengl3.cpp
)
add_library(imgui_static STATIC ${IMGUI_SOURCES})
target_include_directories(imgui_static PUBLIC
        lib/imgui
        lib/imgui/backends
)
target_link_libraries(imgui_static PUBLIC glad_static glfw)

add_library(glm INTERFACE)
target_include_directories(glm INTERFACE lib/glm/include)

add_library(entt_static INTERFACE)
target_include_directories(entt_static INTERFACE lib/entt/single_include)

add_subdirectory(lib/glfw)
add_subdirectory(lib/spdlog)

add_library(Carovan_dependencies STATIC ${ENGINE_SOURCES}
        Carovan.cpp)
target_include_directories(Carovan_dependencies PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(Carovan_dependencies
        PUBLIC
        glad_static
        imgui_static
        glm
        entt_static
        glfw
        spdlog::spdlog
)
