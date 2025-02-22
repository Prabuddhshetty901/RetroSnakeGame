#pragma once

#include<iostream>


#include "Snake.h"
#include "Food.h"


class Game
{
public: 
	Snake snake = Snake();
	Food food = Food(snake.body);

public:
	void Draw();
	void Update();
	void SnakeMove();
	void CheckCollisionWihtFood();
};

