# CMakeList.txt : CMake project for Chat, include source and define
# project specific logic here.
#

cmake_minimum_required(VERSION 3.0)
cmake_policy(SET CMP0011 NEW)
cmake_policy(SET CMP0003 NEW)

# Add source to this project's executable.
add_executable (Chat "Chat.cpp"  "UseImGui.cpp" "UseImGui.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Chat PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
find_package(OpenGL REQUIRED)
target_link_libraries(Chat PRIVATE OpenGL::GL)

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(Chat PRIVATE glfw opengl32)

find_package(imgui CONFIG REQUIRED)
target_link_libraries(Chat PRIVATE imgui::imgui)
