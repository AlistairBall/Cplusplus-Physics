#pragma once
#include "MMath.h"
#include "Scene.h"
#include "gdWorld.h"

#include <vector>

#include "Planet.h"

#include <SDL.h>

using namespace MATH;
class Scene0 : public Scene {
protected:
	SDL_Window *window;
	Matrix4 projectionMatrix;

	gdWorld* world;

	std::vector<GameObject*> planetList;

public:
	Scene0(SDL_Window* sdlWindow);
	~Scene0();
	bool OnCreate();
	void OnDestroy();
	void Update(const float time);
	void Render();
	void HandleEvents(const SDL_Event& SDLEvent);
};

