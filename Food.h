#pragma once
#include<raylib.h>


extern int cellSize;
extern Color darkGreen;
extern int cellCount;

class Food
{
public:
	Vector2 position; // x and y coordinates
	Texture2D texture;

public:
	Food();
	~Food();
	void Draw();
	Vector2 GenerateRandomPos();

};

