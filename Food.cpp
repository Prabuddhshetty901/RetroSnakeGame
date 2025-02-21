#include "Food.h"



Food::Food() {
	Image image = LoadImage("./Graphics/food.png");
	texture = LoadTextureFromImage(image);
	UnloadImage(image);

	position = GenerateRandomPos();
}

Food::~Food() {
	UnloadTexture(texture);
}

void Food::Draw() {
	DrawTexture(texture, position.x * cellSize, position.y * cellSize,WHITE);
}

Vector2 Food::GenerateRandomPos() {
	float x = GetRandomValue(0, cellCount - 1);
	float y = GetRandomValue(0, cellCount - 1);

	return Vector2{x,y};
}