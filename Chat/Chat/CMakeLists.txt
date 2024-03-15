cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (Chat "InitGUI.cpp"  "UseImGui.cpp" "UseImGui.h" "ChatApp.cpp" "ChatApp.h" "WebSocketServer.cpp" "WebSocketServer.h" "Application.cpp" "Application.h" "WebSocketClient.cpp")

# TODO: Add tests and install targets if needed.
find_package(glad CONFIG REQUIRED)
target_link_libraries(Chat PRIVATE glad::glad)

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(Chat PRIVATE glfw)

find_package(imgui CONFIG REQUIRED)
target_link_libraries(Chat PRIVATE imgui::imgui)

find_package(OpenSSL REQUIRED)
target_link_libraries(Chat PRIVATE OpenSSL::SSL OpenSSL::Crypto)

find_package(ZLIB REQUIRED)
target_link_libraries(Chat PRIVATE ZLIB::ZLIB)

find_package(websocketpp CONFIG REQUIRED)
target_link_libraries(Chat PRIVATE websocketpp::websocketpp)

find_package(Boost REQUIRED COMPONENTS random)
target_link_libraries(Chat PRIVATE Boost::boost Boost::random)
