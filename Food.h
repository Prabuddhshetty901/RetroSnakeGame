#pragma once
#include<raylib.h>
#include<raymath.h>
#include<deque>

using namespace std;

extern int cellSize;
extern Color darkGreen;
extern int cellCount;
extern int offset;

class Food
{
public:
	Vector2 position; // x and y coordinates
	Texture2D texture;

public:
	Food(deque<Vector2> snakeBody);
	~Food();
	void Draw();
	Vector2 GenerateRandomPos(deque<Vector2> snakeBody);
	Vector2 GenerateRandomCell();
	bool ElementInDeque(Vector2 element, deque<Vector2> deque);

};

