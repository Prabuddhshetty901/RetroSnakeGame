#include<iostream>
#include<raylib.h>


#include "Game.h"

using namespace std;

int cellSize = 30;
int cellCount = 25;
double lastUpdateTime = 0;
Color green = { 173,204,96,255 };
Color darkGreen = { 43,51,24,255 };
int offset = 75;

bool eventTriggered(double interval) {
	double currentTime = GetTime();
	if (currentTime - lastUpdateTime >= interval) {
		lastUpdateTime = currentTime;
		return true;
	}
	return false;
}	


int main() {


	int screen_width = 2 * offset + cellSize * cellCount;
	int screen_height = 2 * offset + cellSize * cellCount;

	cout << "Starting game..." << endl;

	InitWindow(screen_width, screen_height,"Retro Snake Game");
	SetTargetFPS(60);

	//Creating Objects
	Game game =  Game();


	while (WindowShouldClose() == false) {


		BeginDrawing();

		if (eventTriggered(0.2)) {
			game.Update();
		}

		game.SnakeMove();
		
		//Drawing
		ClearBackground(green); 
		DrawRectangleLinesEx(Rectangle{ (float)offset - 5, (float)offset - 5, (float)cellSize * cellCount + 10, (float)cellSize * cellCount + 10 }, 5, darkGreen);
		DrawText("Retro Snake", offset - 5, 20, 40, darkGreen);
		DrawText(TextFormat("Score: %i",game.score), offset - 5, offset + cellSize * cellCount + 10, 40, darkGreen);
		DrawText(TextFormat("High Score: %i", game.highScore),  cellSize * cellCount - 180, offset + cellSize * cellCount + 10, 40, darkGreen);
		game.Draw();

		EndDrawing();

	}



	CloseWindow();
	return 0;
}