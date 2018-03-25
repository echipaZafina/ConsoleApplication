#pragma once

#include <Windows.h>
#include <iostream>

using namespace std;

class KeyHandler {
public:
	KeyHandler();
	~KeyHandler();
	int getInput();

	enum key {
		ARROW_DOWN,
		ARROW_UP,
		ARROW_LEFT,
		ARROW_RIGHT,
		SPACE,
		ESC,
		NUMBER_OF_KEYS,
		UNKNOWN = -1,
		NO_KEY
	};
private:
	bool keyPressed[NUMBER_OF_KEYS];
	bool keyInfo(int keyIndex, bool pressed = true);
};

