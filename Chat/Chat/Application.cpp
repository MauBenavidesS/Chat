#include "ChatApp.h"
#include "WebSocketServer.h"
#include "WebSocketClient.h"

int Mode = 0; // 0 for Server, 1 for Client

void Application(void) {
	if (Mode == 0) {
		WebSocketClient();
	}
	else if (Mode == 1) {
		ChatApp();
	}
}
