#include "SDL.h"
#include <cstdlib>

#include "ball.h"
#include "block.h"
#include "game.h"



void update()
{
	//entityManager.refresh();
	entityManager.update();
}

int main()
{
	SDL_Init(SDL_INIT_EVERYTHING); 
	window = SDL_CreateWindow("Arkanoid", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth,screenHeight,0); 
	render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	
	bool running = true;

	for (int x = 0; x < grid.width; ++x)
	{
		for (int y = 0; y < grid.height; ++y)
		{
			Block* block = &entityManager.addEntity<Block>();
			block->transform->position = grid.getPositionOfVertex(x, y);
			block->collider->dimensions = { blockWidth, blockHeight };
			block->sprite->dimensions = block->collider->dimensions;
		}
	}
	for (int y = 0; y < 1; ++y)
	{
		Ball* ball = &entityManager.addEntity<Ball>();
		ball->transform->position = Vector2(200, 200);
	}
	entityManager.addEntity<Player>();

	while (running)
	{
		
		setDeltaTime();
		SDL_Event event;
		while(SDL_PollEvent(&event)) 
		{
			switch (event.type)
			{
				case SDL_QUIT:
					running = false;
					break;

				case SDL_KEYDOWN:
				{
					int scancode = event.key.keysym.scancode;
					if (scancode == SDL_SCANCODE_ESCAPE)
						running = false;
	
					keys[scancode] = true;

					break;
				}

				case SDL_KEYUP:
				{
					int scancode = event.key.keysym.scancode;
					keys[scancode] = false;
					break;
				}
			}
		}
		SDL_SetRenderDrawColor(render, 25, 25, 40, 255);
		SDL_RenderClear(render);
		update();
		
		SDL_RenderPresent(render);
 
		SDL_Delay(16); 
	}
}
