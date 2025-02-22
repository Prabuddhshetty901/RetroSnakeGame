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
	int score = 0;
	int highScore = 0;
	Sound eatSound;
	Sound wallSound;

public:
	Game();
	~Game();
	void Draw();
	void Update();
	void SnakeMove();
	void CheckCollisionWihtFood();
	void CheckCollisionWithEdges();
	void CheckCollisionWithTail();
	void GameOver();
};

