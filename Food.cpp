#include "Food.h"



Food::Food(deque<Vector2> snakeBody) {
	Image image = LoadImage("./Graphics/food.png");
	texture = LoadTextureFromImage(image);
	UnloadImage(image);

	position = GenerateRandomPos(snakeBody);
}

Food::~Food() {
	UnloadTexture(texture);
}

void Food::Draw() {
	DrawTexture(texture, offset + position.x * cellSize, offset + position.y * cellSize,WHITE);
}

Vector2 Food::GenerateRandomPos(deque<Vector2> snakeBody) {

	Vector2 l_position = GenerateRandomCell();
	while (ElementInDeque(l_position, snakeBody)) {
		l_position = GenerateRandomCell();
	}
	return l_position;
}

Vector2 Food::GenerateRandomCell() {
	float x = GetRandomValue(0, cellCount - 1);
	float y = GetRandomValue(0, cellCount - 1);
	return Vector2{ x,y };
}


bool Food::ElementInDeque(Vector2 element, deque<Vector2> deque) {
	for (unsigned int i = 0; i < deque.size(); i++) {
		if (Vector2Equals(deque[i], element)) {
			return true;
		}
	}
	return false;
}