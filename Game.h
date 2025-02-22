#pragma once

#include<iostream>
#include<raylib.h>

#include "Snake.h"
#include "Food.h"


extern Color green;
extern Color darkGreen;
extern int cellSize;
extern int cellCount;
extern int offset;

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
	void ResetPage();
	bool GameState();
};

