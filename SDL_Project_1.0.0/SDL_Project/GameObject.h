//equivilant to pragma once
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>

#include "SDL.h"
#include "Matrix.h"
#include "gdBody.h"
#include <SDL_image.h>


using namespace MATH;

class GameObject {
	public:
		GameObject() {}
		virtual ~GameObject() {}

		
		virtual bool OnCreate() = 0;
		virtual void OnDestroy() = 0;
		virtual void Update(double timestep) = 0;
		virtual void Render() = 0;
	
		gdBody* body;


	protected:
		SDL_Surface* image;
		SDL_Rect rect;

		std::string imageName;

		Matrix4 projectionMatrix;
		SDL_Window* window;
};
#endif // !GAMEOBJECT_H