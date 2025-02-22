#pragma once
#include<raylib.h>
#include<deque>
#include<raymath.h>


extern int cellSize;
extern Color darkGreen;
extern int cellCount;


using namespace std;



class Snake
{
public:
	deque<Vector2> body = { Vector2{6,9}, Vector2{5,9}, Vector2{4,9} };
	Vector2 direction = { 1,0 };
	bool addSegment = false;

public:
	void Draw();
	void Update();
	void Reset();
};

