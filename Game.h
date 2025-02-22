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
	const char* r_text = "PRESS 'R' TO START OVER";
	const char* w_text = "YOU WON!!!";
	const char* l_text = "GAME OVER!!!";
	const char* s_text = "Score: %i";
	const char* h_text = "High Score: %i";
	int win_score = 3;

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
	void GameWon();
	void ResetPage();
	bool GameState();
};

