/*
 * rect.h
 *
 *  Created on: 23.04.2017
 *      Author: omer
 */

#pragma once
#include "window.h"
#include <string.h>
class Rect : public Window {
public:
	Rect(const Window &window,int w,int h,int x,int y,int r,int g, int b,int a);
	void draw();
	void pollEvent(SDL_Event event);

private:
	int _w,_h;
	int _x,_y;
	int _r,_g,_b,_a;


};





