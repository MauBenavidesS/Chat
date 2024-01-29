#include "UseImGui.h"
#include <algorithm>
#include <vector>

// Constants
const int MAX_MESSAGES = 100;
const int MIN_CHARACTER = 1;
const int MAX_INPUT_LENGTH = 256;

// Our state
bool show_demo_window = true;
bool show_another_window = false;
ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

std::vector<std::vector<char>> messages;
int messageCount = 0;
char inputBuffer[MAX_INPUT_LENGTH] = "";

void UseImGui::Init(GLFWwindow* window, const char* glsl_version)
{
    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // Enable Docking
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;       // Enable Multi-Viewport / Platform Windows

    // Setup Platform/Renderer bindings
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);
    ImGui::StyleColorsDark();
}

void UseImGui::NewFrame()
{
    // feed inputs to dear imgui, start new frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void UseImGui::Update()
{
    ImGuiIO& io = ImGui::GetIO();

    ImGui::Begin("Chat++", NULL, ImGuiWindowFlags_NoCollapse);
    ImGui::BeginChild("ChatLog", ImVec2(0, -ImGui::GetTextLineHeightWithSpacing() - 10));

    // Display chat messages
    for (int i = 0; i < messageCount; ++i) {
        ImGui::TextWrapped("%s", messages[i].data());
    }

    ImGui::EndChild();
    ImGui::Separator();

    // Input box    
    ImGui::SetKeyboardFocusHere();
    ImGui::InputText("##Input", inputBuffer, IM_ARRAYSIZE(inputBuffer));
    ImGui::SameLine();

    // Send 
    if ((ImGui::Button("Send") || ImGui::IsKeyPressed(ImGuiKey_Enter)) && messageCount < MAX_MESSAGES && strlen(inputBuffer) >= MIN_CHARACTER) {
        // Add the new message at the bottom
        std::vector<char> messageVector(std::begin(inputBuffer), std::end(inputBuffer));
        messages.push_back(messageVector);

        // Increment message count if not at maximum
        messageCount = std::min(messageCount + 1, MAX_MESSAGES);

        // Clear the input box
        inputBuffer[0] = '\0';
    }

    ImGui::End();
}

void UseImGui::Render()
{
    // Render dear imgui into screen
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void UseImGui::Shutdown()
{
    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}
