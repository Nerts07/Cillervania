#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "renderWindow.hpp"
#include "Entity.hpp"

using namespace std;



RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h)	:window(NULL), renderer(NULL)
{
	window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	xWidth = p_w / 64.f;

}

SDL_Texture* RenderWindow::loadTexture(const char *p_filePath)
{
	SDL_Texture *texture = NULL;
	texture = IMG_LoadTexture(renderer, p_filePath);
	return texture;
}

void RenderWindow::cleanUp()
{
	SDL_DestroyWindow(window);
}

void RenderWindow::clear()
{
	SDL_RenderClear(renderer);
}

void RenderWindow::render(Entity& p_entity)
{
	SDL_Rect src;
	src.x = p_entity.getCurrentFrame().x;
	src.y = p_entity.getCurrentFrame().y;
	src.w = p_entity.getCurrentFrame().w;
	src.h = p_entity.getCurrentFrame().h;

	SDL_Rect dst;
	dst.x = p_entity.getx();
	dst.y = p_entity.gety();
	dst.w = p_entity.getCurrentFrame().w * 2;
	dst.h = p_entity.getCurrentFrame().h * 2;

	SDL_RenderCopy(renderer, p_entity.getTex(), &src, &dst);
}
void RenderWindow::display()
{
	SDL_RenderPresent(renderer);
}

float RenderWindow::getXWid()
{
	return xWidth;
}