# CMakeList.txt : CMake project for Chat, include source and define

cmake_minimum_required(VERSION 3.12)
project(Chat)

# Add source to this project's executable.
add_executable(Chat "Chat.cpp" "imgui_impl/imgui_impl_opengl3.cpp" "imgui_impl/imgui_impl_glfw.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
    set_property(TARGET Chat PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.

# Find GLFW3 package
find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(Chat PRIVATE glfw)

# Find ImGui package
find_package(imgui CONFIG REQUIRED)
target_link_libraries(Chat PRIVATE imgui::imgui)

# Find OpenGL package
find_package(OpenGL REQUIRED)
target_link_libraries(Chat PRIVATE OpenGL::GL)
