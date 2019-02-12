#include "Scene1.h"
#include "Jetski.h"
#include <SDL.h>



Scene1::Scene1(SDL_Window* sdlWindow_) {
	window = sdlWindow_;
	

	JetskiList = std::vector<GameObject*>();
}

Scene1::~Scene1() {
	for (auto planet : JetskiList) {
	
		delete planet;
		planet = nullptr;

	}

	

	JetskiList.clear();
	JetskiList.shrink_to_fit();
}

bool Scene1::OnCreate() {
	int w, h;
	SDL_GetWindowSize(window, &w, &h);



	projectionMatrix = MMath::viewportNDC(w, h) * MMath::orthographic(0.0f, 50.0f, 0.0f, 25.0f, 0.0f, 1.0f);

	GameObject* tmpJetski = new Jetski(projectionMatrix, window, std::string("jetski.bmp"), gdVec2(5.0, 5.0), true, gdVec2(10, 0.0));
	
	JetskiList.push_back(tmpJetski);





	return true;
}

void Scene1::OnDestroy() {}

void Scene1::Update(const float timestep) {
	for (auto Jetski : JetskiList) {
		Jetski->Update(timestep);


	}

}

void Scene1::HandleEvents(const SDL_Event& SDLEvent) {

}

void Scene1::Render() {

	SDL_Surface *screenSurface = SDL_GetWindowSurface(window);
	SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0xff, 0xff, 0xff));

	for (auto jetski : JetskiList) {
		jetski->Render(); 
	}




	SDL_UpdateWindowSurface(window);
}