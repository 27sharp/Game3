/*
 * window.h
 *
 *  Created on: 23.04.2017
 *      Author: omer
 */
#pragma once

#include <string.h>
#include <SDL2/SDL.h>
#include <iostream>


class Window {
public:
	Window(const std::string &title, int width,int height);
	~Window();
	int getWidth() { return _width; }
	int getHeight() { return _height; }
	inline bool isClosed(){
		return _closed;
	}
	void pollEvents(SDL_Event event);
	void  clear();

private:
	bool init();
	std::string _title;
	int _width;
	int _height;

	bool _closed;

	SDL_Window* _window;
protected:
	SDL_Renderer* _renderer;
};






