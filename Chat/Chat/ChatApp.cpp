#include "UseImGui.h"
#include <vector>
#include <string>

// Constants
const int MAX_MESSAGES = 100;
const int MIN_CHARACTER = 1;
const int MAX_INPUT_LENGTH = 256;

int messageCount = 0;
std::vector<std::string> messages;
char inputBuffer[MAX_INPUT_LENGTH] = "";

// Buttons
static bool send = false;

void ChatApp(void) {
	ImGui::Begin("Chat++", NULL, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoMove);

	ImGui::BeginChild("ChatLog", ImVec2(0, -ImGui::GetTextLineHeightWithSpacing() - 10));
	// Display chat messages
	for (int i = 0; i < messageCount; ++i) {
		ImGui::TextWrapped("%s", messages[i].data());
	}
	ImGui::EndChild();


	ImGui::Separator();

	////// Check if the mouse is hovering over the specific child window
	//bool hoveringOverChatLog = ImGui::IsWindowHovered(ImGuiHoveredFlags_ChildWindows);
	bool isMouseLeftPressed = ImGui::IsMouseDown(ImGuiMouseButton_Left);
	bool isChatWindowFocused = ImGui::IsWindowFocused();

	if (send || (ImGui::IsKeyPressed(ImGuiKey_Enter) && messageCount < MAX_MESSAGES&& strlen(inputBuffer) >= MIN_CHARACTER)) {
		ImGui::SetKeyboardFocusHere();
	}
	ImGui::InputText("##Input", inputBuffer, IM_ARRAYSIZE(inputBuffer));
	ImGui::SameLine();
	send = ImGui::Button("Send");
	if ((send || ImGui::IsKeyPressed(ImGuiKey_Enter)) && messageCount < MAX_MESSAGES && strlen(inputBuffer) >= MIN_CHARACTER) {
		printf("1. Send pressed. \n");
		ImGuiID buttonID = ImGui::GetID("Send");
		printf("Button ID: %u\n", buttonID);

		// Add the new message at the bottom
		std::string message(inputBuffer);
		messages.push_back(message);

		// Increment message count if not at maximum
		messageCount = std::min(messageCount + 1, MAX_MESSAGES);

		// Clear the input box
		inputBuffer[0] = char(0);
	}

	//// Drag
	////// 1. Detect Drag // 2. Know text position.
	//bool isDragging0 = ImGui::IsMouseDragging(0, -1.0f);
	//bool isDragging1 = ImGui::IsMouseDragging(1, -1.0f);
	//bool isDragging2 = ImGui::IsMouseDragging(2, -1.0f);

	//if (isDragging0) {
	//	printf("0. Mouse is dragging. \n");
	//}
	//else if (isDragging1) {
	//	printf("1. Mouse is dragging. \n");
	//}
	//else if (isDragging2) {
	//	printf("2. Mouse is dragging. \n");
	//}

	ImGui::End();
}