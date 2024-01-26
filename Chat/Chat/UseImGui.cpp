#include "UseImGui.h"
#include <algorithm>
#include <vector>

// Our state
bool show_demo_window = true;
bool show_another_window = false;
ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

const int MaxMessages = 100;
const int MinCharacter = 1;
std::vector<std::vector<char>> messages;
//char messages[MaxMessages][256];
int messageCount = 0;
char inputBuffer[256] = "";

void UseImGui::Init(GLFWwindow* window, const char* glsl_version)
{
	// Setup Dear ImGui context
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;		  // Enable Docking
	io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;		  // Enable Multi-Viewport / Platform Windows

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
	//ImGui::SetWindowSize(ImVec2(400, 300));
	//ImGui::SetWindowPos(ImVec2(100, 100));
	ImGui::BeginChild("ChatLog", ImVec2(0, -ImGui::GetTextLineHeightWithSpacing() - 10));

	// Display chat messages
	for (int i = 0; i < messageCount; ++i) {
		ImGui::TextWrapped("%s", messages[i].data());
	}

	ImGui::EndChild();
	ImGui::Separator();

	// Input box
	ImGui::SetItemDefaultFocus();
	ImGui::InputText("##Input", inputBuffer, IM_ARRAYSIZE(inputBuffer));
	ImGui::SameLine();
	

	// Send button
	if ((ImGui::Button("Send") || ImGui::IsKeyPressed(ImGuiKey_Enter)) && messageCount < MaxMessages && strlen(inputBuffer) >= MinCharacter) {
		// Shift existing messages up
		/*for (int i = MaxMessages - 1; i > 0; --i) {
			strcpy_s(messages[i], messages[i - 1]);
		}*/

		// Add the new message at the bottom
		//strcpy_s(messages[0], inputBuffer);
		std::vector<char> messageVector(std::begin(inputBuffer), std::end(inputBuffer));
		messages.push_back(messageVector);

		// Increment message count if not at maximum
		messageCount = std::min(messageCount + 1, MaxMessages);

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
