#include "Scene3.h"
#include <SDL.h>



Scene3::Scene3(SDL_Window* sdlWindow_)
{
	window = sdlWindow_;
	world = nullptr;

	ballList = std::vector<GameObject*>();
	



	
}


Scene3::~Scene3()
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



}

bool Scene3::OnCreate() {
	int w, h;
	SDL_GetWindowSize(window, &w, &h);

	world = new gdWorld();

	
	projectionMatrix = MMath::viewportNDC(w, h) * MMath::orthographic(0.0f, 100.0f, 0.0f, 50.0f, 0.0f, 1.0f);

	
		
		//                                                               Image          location                    velocity
		
		GameObject*	ball = new Ball(projectionMatrix, window, std::string("Ball.png"), gdVec2(10,50), 1.0, true, gdVec2(-20,-30));
		world->addBody(ball->body);
		ballList.push_back(ball);

		GameObject*	ball_1 = new Ball(projectionMatrix, window, std::string("Ball.png"), gdVec2(20, 15), 1.0, true, gdVec2(30, 30));
		world->addBody(ball_1->body);
		ballList.push_back(ball_1);

		
	GameObject*	ball_2 = new Ball(projectionMatrix, window, std::string("Ball.png"), gdVec2(30, 38), 1.0, true, gdVec2(20, -30));
		world->addBody(ball_2->body);
		ballList.push_back(ball_2);

		GameObject*	ball_3 = new Ball(projectionMatrix, window, std::string("Ball.png"), gdVec2(40, 21), 1.0, true, gdVec2(-20, -30));
		world->addBody(ball_3->body);
		ballList.push_back(ball_3);

		GameObject*	ball_4 = new Ball(projectionMatrix, window, std::string("Ball.png"), gdVec2(50, 12), 1.0, true, gdVec2(20, 30));
		world->addBody(ball_4->body);
		ballList.push_back(ball_4);
		
		
		GameObject*	ball_5 = new Ball(projectionMatrix, window, std::string("Ball.png"), gdVec2(70, 30), 1.0, true, gdVec2(-20, 30));
		world->addBody(ball_5->body);
		ballList.push_back(ball_5);
		

		GameObject*	ball_6 = new Ball(projectionMatrix, window, std::string("Ball.png"), gdVec2(43, 22), 1.0, true, gdVec2(20, -30));
		world->addBody(ball_6->body);
		ballList.push_back(ball_6);
		
		GameObject*	ball_7 = new Ball(projectionMatrix, window, std::string("Ball.png"), gdVec2(55, 50), 1.0, true, gdVec2(20, -30));
		world->addBody(ball_7->body);
		ballList.push_back(ball_7);

		
		GameObject*	ball_8 = new Ball(projectionMatrix, window, std::string("Ball.png"), gdVec2(18, 44), 1.0, true, gdVec2(20, -30));
		world->addBody(ball_8->body);
		ballList.push_back(ball_8);

		GameObject*	ball_9 = new Ball(projectionMatrix, window, std::string("Ball.png"), gdVec2(12, 11), 1.0, true, gdVec2(-20, -30));
		world->addBody(ball_9->body);
		ballList.push_back(ball_9);

		GameObject*	ball_10 = new Ball(projectionMatrix, window, std::string("Ball.png"), gdVec2(34, 49), 1.0, true, gdVec2(-20, 30));
		world->addBody(ball_10->body);
		ballList.push_back(ball_10);

		GameObject*	ball_11 = new Ball(projectionMatrix, window, std::string("Ball.png"), gdVec2(22, 33), 1.0, true, gdVec2(20, -30));
		world->addBody(ball_11->body);
		ballList.push_back(ball_11);
		





		
		return true;
	}

	




void Scene3::OnDestroy() {}

void Scene3::Update(const float time) {

	

	
	world->Update(time);

	

}


void Scene3::HandleEvents(const SDL_Event& SDLEvent) {

}


void Scene3::Render() {

	SDL_Surface *screenSurface = SDL_GetWindowSurface(window);
	SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0xff, 0xff, 0xff));

	for (auto ball : ballList) {
		ball->Render();
	}






	SDL_UpdateWindowSurface(window);
}