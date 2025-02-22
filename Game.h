#pragma once

#include<iostream>


#include "Snake.h"
#include "Food.h"


class Game
{
public: 
	Snake snake = Snake();
	Food food = Food(snake.body);
	bool running = true;

public:
	void Draw();
	void Update();
	void SnakeMove();
	void CheckCollisionWihtFood();
	void CheckCollisionWithEdges();
	void CheckCollisionWithTail();
	void GameOver();
};

