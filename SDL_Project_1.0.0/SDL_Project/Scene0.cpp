#include "Scene0.h"
#include <SDL.h>



Scene0::Scene0(SDL_Window* sdlWindow_){
	window = sdlWindow_;
	world = nullptr;

	planetList = std::vector<GameObject*>();
}

Scene0::~Scene0(){
	//for every planet in the planetlist
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

bool Scene0::OnCreate() {
	int w, h;
	SDL_GetWindowSize(window,&w,&h);

	world = new gdWorld();

	//
	projectionMatrix = MMath::viewportNDC(w,h) * MMath::orthographic(0.0f, 50.0f, 0.0f, 25.0f, 0.0f, 1.0f) ;

	//creating gameobject                                            Image                       Position      Mass  Bool   Initial velocity
	GameObject* tmpPlanet = new Planet(projectionMatrix, window, std::string("jetski.bmp"), gdVec2(22.0, 20.0), 1.0, true, gdVec2(3.0, -2.9));
	world->addBody(tmpPlanet->body);
	planetList.push_back(tmpPlanet);
	

	bool isDynamic = false;
	GameObject* tmpPlanet2 = new Planet(projectionMatrix, window, std::string("sun.png"), gdVec2(13.0, 15.0), 100, isDynamic);
	world->addBody(tmpPlanet2->body);
	planetList.push_back(tmpPlanet2);


	GameObject* tmpPlanet3 = new Planet(projectionMatrix, window, std::string("sun.png"), gdVec2(35.0, 15.0), 150, isDynamic);
	world->addBody(tmpPlanet3->body);
	planetList.push_back(tmpPlanet3);
	


	return true;
}

void Scene0::OnDestroy() {}

void Scene0::Update(const float time) {
	world->Update(time);

}


void Scene0::HandleEvents(const SDL_Event& SDLEvent) {

}


void Scene0::Render() {

	SDL_Surface *screenSurface = SDL_GetWindowSurface(window);
	SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0xff, 0xff, 0xff));
	
	for (auto planet : planetList) {
		planet->Render();
	}




	SDL_UpdateWindowSurface(window);
}