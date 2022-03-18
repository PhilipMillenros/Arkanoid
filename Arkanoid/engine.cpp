#include "engine.h"

SDL_Window* window;
SDL_Renderer* render;

bool keys[SDL_NUM_SCANCODES] = { false };

double deltaTime = 0;
Uint64 previousTime;
Uint64 currentTime;
int screenWidth = 1920;
int screenHeight = 1080;

void setDeltaTime()
{
	previousTime = currentTime;
	currentTime = SDL_GetPerformanceCounter();
	deltaTime = static_cast<double>(currentTime - previousTime) / static_cast<double>(SDL_GetPerformanceFrequency());
}
