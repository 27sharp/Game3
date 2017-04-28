/*
 * player.h
 *
 *  Created on: 26.04.2017
 *      Author: omer
 */
#pragma once
#include "window.h"
#include <string.h>
class Player : public Window {
public:
	Player(const Window &window,int w,int h,int x,int y,const std::string &img_path);
	~Player();
	void drawImage();
	void pollEvent(SDL_Event);
private:
	int _w,_h;
	int _x,_y;
	SDL_Texture *tennis_texture;
};





