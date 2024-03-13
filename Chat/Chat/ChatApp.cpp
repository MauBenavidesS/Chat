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
static bool messageSent = false;

void ChatApp(void) {
	ImGui::Begin("Chat++", NULL, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoMove);

	ImGui::BeginChild("ChatLog", ImVec2(0, -ImGui::GetTextLineHeightWithSpacing() - 10));
	// Display chat messages
	for (int i = 0; i < messageCount; ++i) {
		ImGui::TextWrapped("%s", messages[i].data());
	}

	// Scroll down to see latest messages
	if (messageSent) {
		ImGui::SetScrollHereY(1.0f);
		messageSent = false;
	}
	ImGui::EndChild();


	ImGui::Separator();

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

		// Scroll down to see latest messages
		if (ImGui::GetScrollY() >= ImGui::GetScrollMaxY()) {
			messageSent = true;
		}
	}

	ImGui::End();
}