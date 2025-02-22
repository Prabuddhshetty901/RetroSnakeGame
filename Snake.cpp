#include "Snake.h"



void Snake::Draw() {
	float x;
	float y;
	Rectangle seg;

	for (unsigned int i = 0; i < body.size();i++) {
		x = body[i].x;
		y=body[i].y;
		seg = Rectangle{ offset + x * cellSize, offset + y * cellSize, (float)cellSize, (float)cellSize};

		DrawRectangleRounded(seg, 0.5, 6,darkGreen);
	}
}

void Snake :: Update() {
	
	body.push_front(Vector2Add(body[0], direction));
	
	if (addSegment == true) {
		addSegment = false;
	}
	else {
		body.pop_back();
	}
}



void Snake::Reset() {
	body = { Vector2{ 6,9 }, Vector2{ 5,9 }, Vector2{ 4,9 } };
	direction = { 1,0 };
	addSegment = false;
}