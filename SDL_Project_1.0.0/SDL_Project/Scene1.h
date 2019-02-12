#pragma once
#include "MMath.h"
#include "Scene.h"


#include <vector>

#include "Planet.h"

#include <SDL.h>

using namespace MATH;
class Scene1 : public Scene {
private:
	SDL_Window *window;
	Matrix4 projectionMatrix;

	

	std::vector<GameObject*> JetskiList;

public:
	Scene1(SDL_Window* sdlWindow);
	~Scene1();
	bool OnCreate();
	void OnDestroy();
	void Update(const float time);
	void Render();
	void HandleEvents(const SDL_Event& SDLEvent);
};

