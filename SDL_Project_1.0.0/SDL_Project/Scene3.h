#pragma once
#include "MMath.h"
#include "Scene.h"
#include "gdWorld.h"
#include "Ball.h"
#include "Randomizer.h"
#include <vector>

#include "Planet.h"

#include <SDL.h>

using namespace MATH;
class Scene3 : public Scene {
private:
	SDL_Window *window;
	Matrix4 projectionMatrix;

	gdWorld* world;

	std::vector<GameObject*> ballList;
	std::vector<GameObject*> planetList;

	Randomizer* randomizer;


public:
	Scene3(SDL_Window* sdlWindow);
	~Scene3();
	bool OnCreate();
	void OnDestroy();
	void Update(const float time);
	void Render();
	void HandleEvents(const SDL_Event& SDLEvent);
};

