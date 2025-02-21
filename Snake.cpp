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