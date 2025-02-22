#include<iostream>
#include<raylib.h>


#include "Game.h"

using namespace std;

int cellSize = 30;
int cellCount = 25;
double lastUpdateTime = 0;
Color green = { 173,204,96,255 };
Color darkGreen = { 43,51,24,255 };

bool eventTriggered(double interval) {
	double currentTime = GetTime();
	if (currentTime - lastUpdateTime >= interval) {
		lastUpdateTime = currentTime;
		return true;
	}
	return false;
}	


int main() {


	int screen_width = cellSize*cellCount;
	int screen_height = cellSize * cellCount;

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
		game.Draw();

		EndDrawing();

	}



	CloseWindow();
	return 0;
}