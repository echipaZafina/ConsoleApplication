#include <iostream>

#include "ConsoleHandler.h"
#include "KeyHandler.h"


using namespace std;

int main(int argc, char* argv[]) {
	ConsoleHandler consoleHandler;
	KeyHandler keyHandler;
	while (1) {
		consoleHandler.draw();
		switch (keyHandler.getInput()) {
		case KeyHandler::key::ARROW_UP:
			consoleHandler.movePlayer(0, -1);
			break;
		case KeyHandler::key::ARROW_RIGHT:
			consoleHandler.movePlayer(1, 0);
			break;
		case KeyHandler::key::ARROW_LEFT:
			consoleHandler.movePlayer(-1, 0);
			break;
		case KeyHandler::key::ARROW_DOWN:
			consoleHandler.movePlayer(0, 1);
			break;
		case KeyHandler::key::ESC:
			return 0;
		}
		Sleep(35);
		consoleHandler.clear();
	}

	return 0;
}