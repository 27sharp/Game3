/*
 * window.cpp
 *
 *  Created on: 22.04.2017
 *      Author: omer
 */

#include "window.h"
#include <stdio.h>
#include <SDL2/SDL_image.h>

Window::Window(const std::string &title, int width, int height) :
_title(title), _width(width), _height(height)
{
	if(!init()){
		_closed = true;
	}
}

Window::~Window()
{
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	SDL_Quit();
	IMG_Quit();
}

bool Window::init() {
	if(SDL_Init(SDL_INIT_VIDEO) !=0 ){
		printf("Failed to initalize!");
		return 0;
	}
	if(IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG){
		printf("failed to initalize IMG!");
		return false;
	}

	_window = SDL_CreateWindow(
			_title.c_str(),
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			getWidth(), getHeight(),
			0
	);

	if(_window == nullptr) {
		printf("Failed to create window");
		return 0;
	}

	_renderer = SDL_CreateRenderer(_window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);


	return true;

}
void Window::pollEvents(SDL_Event event){


		switch(event.type){
		case SDL_QUIT:
			_closed = true;
			break;
		case SDL_KEYDOWN:
			std::cout << "Key Pressed!";
			break;
		case SDL_MOUSEMOTION:
			std::cout << event.motion.x << "," << event.motion.y << "\n";
			break;

		default:
			break;
		}
}
void Window::clear()  {
	SDL_RenderPresent(_renderer);
	SDL_SetRenderDrawColor(_renderer,0,0,200,255);
	SDL_RenderClear(_renderer);
}
