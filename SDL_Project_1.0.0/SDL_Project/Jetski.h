#pragma once
#include "GameObject.h"
class Jetski : public GameObject
{
private:
	
	
public:
	Jetski(Matrix4 projMat_, SDL_Window* window_, std::string imageName_, gdVec2 position_, bool isDynamic_ = true, gdVec2 linearVelocity = gdVec2(0.0, 0.0));
	~Jetski();
	virtual bool OnCreate();
	virtual void OnDestroy();
	virtual void Update(double timestep);
	virtual void Render();
};

