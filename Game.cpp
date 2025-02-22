#include "Game.h"

Game::Game() {
	InitAudioDevice();
	eatSound = LoadSound("./Sounds/eat.mp3");
	wallSound = LoadSound("./Sounds/wall.mp3");
}


void Game::Draw() {
	food.Draw();
	snake.Draw();

}

Game::~Game() {
	UnloadSound(eatSound);
	UnloadSound(wallSound);
	CloseAudioDevice();
}

void Game::Update() {
	if (running) {
		snake.Update();
		CheckCollisionWihtFood();
		CheckCollisionWithEdges();
		CheckCollisionWithTail();
	}
}

void Game::SnakeMove() {
	if (IsKeyPressed(KEY_UP) && snake.direction.y != 1) {
		snake.direction = { 0,-1 };
	}
	if (IsKeyPressed(KEY_DOWN) && snake.direction.y != -1) {
		snake.direction = { 0,1 };
	}
	if (IsKeyPressed(KEY_LEFT) && snake.direction.x != 1) {
		snake.direction = { -1,0 };
	}
	if (IsKeyPressed(KEY_RIGHT) && snake.direction.x != -1) {
		snake.direction = { 1,0 };
	}
}

void Game::CheckCollisionWihtFood() {
	if (Vector2Equals(snake.body[0], food.position)) {
		food.position = food.GenerateRandomPos(snake.body);
		snake.addSegment = true;
		score++;
		PlaySound(eatSound);
	}
}

void Game::CheckCollisionWithEdges() {
	if (snake.body[0].x == cellCount || snake.body[0].x == -1) {
		GameOver();
	}
	if (snake.body[0].y == cellCount || snake.body[0].y == -1) {
		GameOver();
	}
	
}

void Game::CheckCollisionWithTail() {
	deque<Vector2> headlessBody = snake.body;
	headlessBody.pop_front();

	if (food.ElementInDeque(snake.body[0], headlessBody)){
		GameOver();
	}
}

void Game::GameOver() {
	snake.Reset();
	food.position = food.GenerateRandomPos(snake.body);
	running = false;
	if (score > highScore) {
		highScore = score;
	}
	PlaySound(wallSound);
}

void Game::ResetPage() {

	const char* text1 = "GAME OVER!!!";
	const char* text2 = "PRESS 'R' TO START OVER";
	
	DrawText(text1, offset + ((cellSize * cellCount) - MeasureText(text1, 60)) / 2 , offset + ((cellSize * cellCount) - MeasureText("GAME OVER!!!", 60)) / 2, 60, darkGreen);
	DrawText(text2, offset + ((cellSize * cellCount) - MeasureText(text2, 30)) / 2, offset + ((cellSize * cellCount) - MeasureText("Press 'R' to start over", 30)) / 2 + 100, 30, darkGreen);
	
	const char* text3 = "Score: %i";
	const char* text4 = "High Score: %i";

	DrawText(TextFormat(text3, score), offset + ((cellSize * cellCount) - MeasureText(text3, 30)) / 2, offset + ((cellSize * cellCount) - MeasureText(text3, 30)) / 2 + 100, 30, darkGreen);
	DrawText(TextFormat(text4, highScore), offset + ((cellSize * cellCount) - MeasureText(text4, 30)) / 2, offset + ((cellSize * cellCount) - MeasureText(text4, 30)) / 2 + 200, 30, darkGreen);

	
	if(IsKeyPressed(KEY_R)) {
		score = 0;
		running = true;
	}
}

bool Game::GameState() {
	return running;
}