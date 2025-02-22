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
		running = true;
	}
	if (IsKeyPressed(KEY_DOWN) && snake.direction.y != -1) {
		snake.direction = { 0,1 };
		running = true;
	}
	if (IsKeyPressed(KEY_LEFT) && snake.direction.x != 1) {
		snake.direction = { -1,0 };
		running = true;
	}
	if (IsKeyPressed(KEY_RIGHT) && snake.direction.x != -1) {
		snake.direction = { 1,0 };
		running = true;
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
	score = 0;
	PlaySound(wallSound);
}