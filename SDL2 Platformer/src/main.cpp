#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

#include "renderWindow.hpp"
#include "Entity.hpp"

using namespace std;
int main(int argv, char* args[]){
	if (SDL_Init(SDL_INIT_VIDEO) > 0){
		std::cout << "ye" << std::endl;
	}
	if (!(IMG_Init(IMG_INIT_PNG)))
	{
		std::cout << " img ye" << std::endl;
	}

	RenderWindow window("JumpKillervania Alpha 0.01", 800, 600);

	SDL_Texture* grassTexture = window.loadTexture("res/gfx/ground_grass_1.png");

	vector<Entity> grasses = {
		Entity (0.f, 540.f, grassTexture),
	 	Entity (60.f, 540.f, grassTexture),
		Entity (120.f, 540.f, grassTexture),
	 	Entity (180.f, 540.f, grassTexture),
		Entity (240.f, 540.f, grassTexture),
		Entity (300.f, 540.f, grassTexture),
		Entity (360.f, 540.f, grassTexture),
	 	Entity (420.f, 540.f, grassTexture),
		Entity (480.f, 540.f, grassTexture),
		Entity (540.f, 540.f, grassTexture),
		Entity (600.f, 540.f, grassTexture),
		Entity (660.f, 540.f, grassTexture),
		Entity (720.f, 540.f, grassTexture),
		Entity (780.f, 540.f, grassTexture)
	};

	bool gameLoop = true;
	SDL_Event event;
	while(gameLoop)
	{
		while(SDL_PollEvent(&event)){
			if (event.type == SDL_QUIT)
			{
				gameLoop = false;
			}
		}

		window.clear();
		for (Entity& c : grasses)
		{
			window.render(c);
		}
		window.display();

	}

	window.cleanUp();
	SDL_Quit();
	
	return 0;
}