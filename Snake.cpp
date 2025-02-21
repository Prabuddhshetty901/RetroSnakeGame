#include "Snake.h"



void Snake::Draw() {
	float x;
	float y;
	Rectangle seg;

	for (unsigned int i = 0; i < body.size();i++) {
		x = body[i].x;
		y=body[i].y;
		seg = Rectangle{ x * cellSize, y * cellSize, (float)cellSize, (float)cellSize};

		DrawRectangleRounded(seg, 0.5, 6,darkGreen);
	}
}

void Snake :: Update() {
	body.pop_back();
	body.push_front(Vector2Add(body[0], direction));
}

void Snake::Move() {
	if (IsKeyPressed(KEY_UP) && direction.y != 1) {
		direction = { 0,-1 };
	}
	if (IsKeyPressed(KEY_DOWN) && direction.y != -1) {
		direction = { 0,1 };
	}
	if (IsKeyPressed(KEY_LEFT) && direction.x != 1) {
		direction = { -1,0 };
	}
	if (IsKeyPressed(KEY_RIGHT) && direction.x != -1) {
		direction = { 1,0 };
	}
}