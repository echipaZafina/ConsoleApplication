#include "ConsoleHandler.h"

ConsoleHandler::ConsoleHandler(unsigned short int posX, unsigned short int posY) {
	playerPosition = Position(posX, posY);

	for (int i = 0; i < sizeX; i++)
		for (int j = 0; j < sizeY; j++)
			v[i][j] = 0;

	//bordare
	for (int i = 0; i < sizeX; i++) {
		v[i][0] = v[i][sizeY - 1] = WALL;
		charV[i][sizeY] = 0;
	}
	for (int i = 0; i < sizeY; i++)
		v[0][i] = v[sizeX - 1][i] = WALL;

	v[playerPosition.getX()][playerPosition.getY()] = PLAYER;

	//completare charV
	for (int i = 0; i < sizeX; i++)
		for (int j = 0; j < sizeY; j++)
			charV[i][j] = associatedChar(v[i][j]);
}

void ConsoleHandler::draw() {
	for (int i = 0; i < sizeY; i++, cout << endl)
		for (int j = 0; j < sizeX; j++)
			cout << charV[j][i];
}

void ConsoleHandler::clear() {
	system("cls");
}

void ConsoleHandler::valueChanged(int posX, int posY) {
	charV[posX][posY] = associatedChar(v[posX][posY]);
}

void ConsoleHandler::valueChanged(Position pos) {
	valueChanged(pos.getX(), pos.getY());
}

char ConsoleHandler::associatedChar(int x) {
	switch (x) {
	case PLAYER:
		return '@';
	case WALL:
		return '#';
	case EMPTY:
		return ' ';
	default:
		return -1;
	};
}

void ConsoleHandler::movePlayer(int x, int y) {
	int posX, posY;
	posX = playerPosition.getX();
	posY = playerPosition.getY();
	if ((posX + x < 0 || posX + x >= sizeX) || (posY + y < 0 || posY + y >= sizeY)) {
		cout << "ERROR : INDEX OUT OF V!!!\n";
		return;
	}
	if (v[posX + x][posY + y] != WALL) {
		playerPosition.moveBy(x, y);
		v[posX][posY] = EMPTY;
		v[playerPosition.getX()][playerPosition.getY()] = PLAYER;
		valueChanged(posX, posY);
		valueChanged(playerPosition);
	}
}

void ConsoleHandler::movePlayerAt(Position pos) {
}
