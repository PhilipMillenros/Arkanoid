#include "SDL.h"
#undef main

extern SDL_Window* window;
extern SDL_Renderer* render;

extern bool keys[SDL_NUM_SCANCODES];

extern double deltaTime;
extern Uint64 previousTime;
extern Uint64 currentTime;
extern int screenWidth;
extern int screenHeight;

void setDeltaTime();

