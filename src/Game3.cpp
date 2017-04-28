


/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and strings
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

#include <stdio.h>
#include <string>
#include "rect.h"
#include "window.h"
#include "player.h"

void pollEvents(Window &window, Rect &rect,Player &player){
	SDL_Event event;
	if(SDL_PollEvent(&event)){
		rect.pollEvent(event);
		window.pollEvents(event);
		player.pollEvent(event);
	}
}

int main( int argc, char* args[] )
{

	Window window("SDL Tut", 800,600);
	Rect rect(window,120,120,100,100,200,0,200,255);
	Player player(window,240,110,100,100,"bob.png");

	while(!window.isClosed()){
		pollEvents(window,rect,player);
		//rect.draw();
		player.drawImage();
		window.clear();
	}
	return 0;
}

/*	for(int i = 0; i < 2000; i++){
	  SDL_PumpEvents();
	  SDL_PumpEvents();
	  SDL_Delay(1);
	}*/

