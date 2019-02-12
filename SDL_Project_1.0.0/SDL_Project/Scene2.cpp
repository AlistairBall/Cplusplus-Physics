#include "Scene2.h"
#include <SDL.h>



Scene2::Scene2(SDL_Window* sdlWindow_)
{
	window = sdlWindow_; 
	world = nullptr;

	ballList = std::vector<GameObject*>();
	planetList = std::vector<GameObject*>();



	randomizer = new Randomizer();
}


Scene2::~Scene2()
{
	for (auto Ball : ballList) {
		world->removeBody(Ball->body);
		delete Ball;
		Ball = nullptr;

	}

	delete world;
	world = nullptr;

	ballList.clear();
	ballList.shrink_to_fit();


	for (auto planet : planetList) {
		world->removeBody(planet->body);
		delete planet;
		planet = nullptr;

	}

	delete world;
	world = nullptr;

	planetList.clear();
	planetList.shrink_to_fit();
}

bool Scene2::OnCreate() {
	int w, h;
	SDL_GetWindowSize(window, &w, &h);

	world = new gdWorld();

	//
	projectionMatrix = MMath::viewportNDC(w, h) * MMath::orthographic(0.0f, 100.0f, 0.0f, 50.0f, 0.0f, 1.0f);

	int randNum = randomizer->rand(10, 15);
	for (int i = 0; i < (randNum); i++) {
		GameObject* ball;
		//   50/50 generator                                             Image                                   Random location                                                          Random velocity
		if (i % 2 == 0) {
			ball = new Ball(projectionMatrix, window, std::string("Ball.png"), gdVec2(randomizer->rand(10.0, 90.0), randomizer->rand(10.0, 40.0)), 1.0, true, gdVec2(randomizer->rand(-3.0, 3.0), randomizer->rand(-3.0, 3.0)));

		}
		else {
			ball = new Ball(projectionMatrix, window, std::string("bigBall.png"), gdVec2(randomizer->rand(10.0, 90.0), randomizer->rand(10.0, 40.0)), 5.0, true, gdVec2(randomizer->rand(-3.0, 3.0), randomizer->rand(-3.0, 3.0)));

		}
		

		//add ball to bodies
		world->addBody(ball->body);
		ballList.push_back(ball);
	}

	GameObject* tmpPlanet1 = new Planet(projectionMatrix, window, std::string("sun.png"), gdVec2(46.0, 28.0), 1000, false);
	world->addBody(tmpPlanet1->body);
	planetList.push_back(tmpPlanet1);


	return true;
}

void Scene2::OnDestroy() {}

void Scene2::Update(const float time) {
	world->Update(time);

}


void Scene2::HandleEvents(const SDL_Event& SDLEvent) {

}


void Scene2::Render() {

	SDL_Surface *screenSurface = SDL_GetWindowSurface(window);
	SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0xff, 0xff, 0xff));


	//render every ball in ball list
	for (auto ball : ballList) {
		ball->Render();
	}
	//render every planet it planetList
	for (auto planet : planetList) {
		planet->Render();
	}





	SDL_UpdateWindowSurface(window);
}