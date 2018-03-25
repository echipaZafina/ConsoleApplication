#include "KeyHandler.h"

KeyHandler::KeyHandler() {
	for (int i = 0; i < NUMBER_OF_KEYS; i++)
		keyPressed[i] = false;
}

KeyHandler::~KeyHandler() {
}

int KeyHandler::getInput() {
	if (keyInfo(ARROW_UP, GetAsyncKeyState(VK_UP)))
		return ARROW_UP;
	if (keyInfo(ARROW_DOWN, GetAsyncKeyState(VK_DOWN)))
		return ARROW_DOWN;
	if (keyInfo(ARROW_LEFT, GetAsyncKeyState(VK_LEFT)))
		return ARROW_LEFT;
	if (keyInfo(ARROW_RIGHT, GetAsyncKeyState(VK_RIGHT)))
		return ARROW_RIGHT;
	if (keyInfo(ESC, GetAsyncKeyState(VK_ESCAPE)))
		return ESC;
	return UNKNOWN;
}

bool KeyHandler::keyInfo(int keyIndex, bool pressed) {
	
	if (!keyPressed[keyIndex] && pressed) {
		keyPressed[keyIndex] = true;
		return true;
	}
	if (!pressed)
		keyPressed[keyIndex] = false;
	return false;
}
