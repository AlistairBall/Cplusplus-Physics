#include "GameManager.h"
#include "Window.h"
#include "Timer.h"
#include "Scene0.h"
#include "Scene1.h"
#include "Scene2.h"
#include "Scene3.h"
#include <iostream>

GameManager::GameManager() {
	timer = nullptr;
	isRunning = true;
	currentScene = nullptr;
}

bool GameManager::OnCreate() {
	const int SCREEN_WIDTH = 1000;
	const int SCREEN_HEIGHT = 600;
	ptr = new Window(SCREEN_WIDTH, SCREEN_HEIGHT);
	if (ptr->OnCreate() == false) {
		OnDestroy();
		return false;
	}

	timer = new Timer();
	if (timer == nullptr) {
		OnDestroy();
		return false;
	}

	currentScene = new Scene2(ptr->GetSDL_Window());
	if (currentScene == nullptr) {
		OnDestroy();
		return false;
	}

	if (currentScene->OnCreate() == false) {
		OnDestroy();
		return false;
	}

	return true;
}
void GameManager::Run() {
	timer->Start();
	while (isRunning) {
		timer->UpdateFrameTicks();

		/// Here's the whole game
	    HandleEvents();
		currentScene->Update(timer->GetDeltaTime());
		currentScene->Render();

		/// Keeep the event loop running at a sane rate
		SDL_Delay(timer->GetSleepTime(60));
	}
}

void GameManager::HandleEvents() {
	SDL_Event SDLEvent;

	while (SDL_PollEvent(&SDLEvent)) {
		switch (SDLEvent.type) {
		case SDL_EventType::SDL_QUIT:
			isRunning = false;
			return;

			currentScene->HandleEvents(SDLEvent);
			break;
		case SDL_EventType::SDL_KEYDOWN:
			switch (SDLEvent.key.keysym.sym) {
			case SDLK_0:
				if (currentScene) delete currentScene;
				currentScene = new Scene0(ptr->GetSDL_Window());
				currentScene->OnCreate();
				break;
			case SDLK_1:
				if (currentScene) delete currentScene;
				currentScene = new Scene1(ptr->GetSDL_Window());
				currentScene->OnCreate();
				break;

			case SDLK_2:
				if (currentScene) delete currentScene;
				currentScene = new Scene2(ptr->GetSDL_Window());
				currentScene->OnCreate();
				break;


			case SDLK_3:
				if (currentScene) delete currentScene;
				currentScene = new Scene3(ptr->GetSDL_Window());
				currentScene->OnCreate();
				break;

			default:
				currentScene->HandleEvents(SDLEvent);
				break;

			}
		}
	}
}

GameManager::~GameManager() {}

void GameManager::OnDestroy(){
	if (ptr) delete ptr;
	if (timer) delete timer;
	if (currentScene) delete currentScene;
}