#pragma once
#include <SDL.h>
#include "Scene.h"

class GameManager {
private:
	class Window *ptr;
	class Timer *timer;
	bool isRunning;
	Scene *currentScene;

public:
	GameManager();
	~GameManager();
	bool OnCreate();
	void OnDestroy();
	void HandleEvents();

	void Run();
};

