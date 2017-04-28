/*
 * player.cpp
 *
 *  Created on: 26.04.2017
 *      Author: omer
 */
#include "player.h"
#include <SDL2/SDL_image.h>

Player::Player(const Window &window,int w,int h,int x,int y,const std::string &img_path) :
Window(window),_w(w),_h(h),_x(x),_y(y) {
	SDL_Surface *surface = IMG_Load(img_path.c_str());
	if(!surface){
		printf("failed to load surface");
	}
	tennis_texture = SDL_CreateTextureFromSurface(_renderer,surface);
	SDL_FreeSurface(surface);
}
Player::~Player(){
	SDL_DestroyTexture(tennis_texture);
}
void Player::drawImage(){
	SDL_Rect rect = {_x,_y,_w,_h};
	SDL_RenderCopy(_renderer,tennis_texture,NULL,&rect);
}
void Player::pollEvent(SDL_Event event){
	if(event.type == SDL_KEYDOWN){
		switch(event.key.keysym.sym){
		case SDLK_LEFT:
			_x -= 20;
			break;
			case SDLK_RIGHT:
				_x += 20;
				break;
			case SDLK_DOWN:
				_y += 10;
				break;
			case SDLK_UP:
				_y -= 10;
				break;

			default:
				break;

				}
			}

}


