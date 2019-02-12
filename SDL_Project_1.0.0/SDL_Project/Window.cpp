#include "Window.h"
#include <SDL.h>
#include <iostream>


Window::Window(int width_, int height_){
	screenSurface = nullptr;
	window = nullptr;
	width = width_;
	height = height_;
}

bool Window::OnCreate(){
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL_Error: " << SDL_GetError() << std::endl;
		return false;
	}

	window = SDL_CreateWindow("My First Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	if (window == nullptr) {
		std::cout << "SDL_Error: " << SDL_GetError() << std::endl;
		return false;
	}

	screenSurface = SDL_GetWindowSurface(window);
	if (screenSurface == nullptr) {
		std::cout << "SDL_Error: " << SDL_GetError() << std::endl;
		return false;
	}
	return true;
}

void Window::OnDestroy(){
	/// Kill the window
	if (window != nullptr){
		SDL_DestroyWindow(window);
	}
	if (screenSurface == nullptr){
		SDL_FreeSurface(screenSurface);
	}
	///Exit the SDL subsystems
	SDL_Quit();

}
Window::~Window(){
	

}

SDL_Window* Window::GetSDL_Window() {
	return window;
}