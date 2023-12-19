# CMakeList.txt : CMake project for Chat, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (Chat "Chat.cpp"  "UseImGui.cpp" "UseImGui.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Chat PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
find_package(Vulkan REQUIRED)
target_link_libraries(Chat PRIVATE Vulkan::Vulkan)

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(Chat PRIVATE glfw)

find_package(imgui CONFIG REQUIRED)
target_link_libraries(Chat PRIVATE imgui::imgui)
