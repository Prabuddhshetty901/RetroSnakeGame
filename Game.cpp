#include "Game.h"


void Game::Draw() {
	food.Draw();
	snake.Draw();

}

void Game::Update() {
	snake.Update();
	CheckCollisionWihtFood();
}

void Game::SnakeMove() {
	snake.Move();
}

void Game::CheckCollisionWihtFood() {
	if (Vector2Equals(snake.body[0], food.position)) {
		food.position = food.GenerateRandomPos(snake.body);
	}
}