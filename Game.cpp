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
		if (score == win_score) {
			GameWon();
		}
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
	/*snake.Reset();*/
	food.position = food.GenerateRandomPos(snake.body);
	running = false;
	if (score > highScore) {
		highScore = score;
	}
	PlaySound(wallSound);
}
void Game::GameWon() {
	food.position = food.GenerateRandomPos(snake.body);
	running = false;
	if (score > highScore) {
		highScore = score;
	}
}

void Game::ResetPage() {


	if (score == win_score) {
		DrawText(w_text, offset + ((cellSize * cellCount) - MeasureText(w_text, 60)) / 2, offset + ((cellSize * cellCount) - MeasureText(w_text, 60)) / 2, 60, darkGreen);
		DrawText(r_text, offset + ((cellSize * cellCount) - MeasureText(r_text, 30)) / 2, offset + ((cellSize * cellCount) - MeasureText(r_text, 30)) / 2 + 130, 30, darkGreen);

		DrawText(TextFormat(s_text, score), offset + ((cellSize * cellCount) - MeasureText(s_text, 30)) / 2, offset + ((cellSize * cellCount) - MeasureText(s_text, 30)) / 2 + 100, 30, darkGreen);
		DrawText(TextFormat(h_text, highScore), offset + ((cellSize * cellCount) - MeasureText(h_text, 30)) / 2, offset + ((cellSize * cellCount) - MeasureText(h_text, 30)) / 2 + 200, 30, darkGreen);
	}
	else {
		DrawText(l_text, offset + ((cellSize * cellCount) - MeasureText(l_text, 60)) / 2, offset + ((cellSize * cellCount) - MeasureText(l_text, 60)) / 2, 60, darkGreen);
		DrawText(r_text, offset + ((cellSize * cellCount) - MeasureText(r_text, 30)) / 2, offset + ((cellSize * cellCount) - MeasureText(r_text, 30)) / 2 + 100, 30, darkGreen);


		DrawText(TextFormat(s_text, score), offset + ((cellSize * cellCount) - MeasureText(s_text, 30)) / 2, offset + ((cellSize * cellCount) - MeasureText(s_text, 30)) / 2 + 100, 30, darkGreen);
		DrawText(TextFormat(h_text, highScore), offset + ((cellSize * cellCount) - MeasureText(h_text, 30)) / 2, offset + ((cellSize * cellCount) - MeasureText(h_text, 30)) / 2 + 200, 30, darkGreen);
	}
	
	if(IsKeyPressed(KEY_R)) {
		snake.Reset();
		score = 0;
		running = true;
	}
}

bool Game::GameState() {
	return running;
}