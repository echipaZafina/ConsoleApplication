#pragma once

#include <iostream>

using namespace std;

struct Position
{
private:
	unsigned short int x, y;
public:
	Position(const unsigned short int x, const unsigned int y):x(x),y(y) {}
	Position() {}
	inline void setX(int x) { this->x = x; }
	inline void setY(int y) { this->y = y; }
	inline unsigned short int& getX() { return x; }
	inline unsigned short int& getY() { return y; }
	inline void moveBy(int xVal, int yVal) {
		x += xVal;
		y += yVal;
	}
};

class ConsoleHandler {
private:
	static const int sizeX = 10, sizeY = 5;
	char charV[sizeX][sizeY + 1];
	short int v[sizeX][sizeY];
	Position playerPosition;
	
	enum {
		EMPTY=0,
		PLAYER,
		WALL,

		ENUM_SIZE
	};

	void valueChanged(int posX, int posY);
	void valueChanged(Position pos);
public:
	ConsoleHandler(unsigned short int posX = 1, unsigned short int posY = 1);
	void draw();
	void clear();
	char associatedChar(int x);
	void movePlayer(int x, int y);
	void movePlayerAt(Position pos);
};

