#pragma once
#include "GameObject.h"



class Planet : public GameObject {
	
	public:
		Planet(Matrix4 projMat_, SDL_Window* window_, std::string imageName_, gdVec2 position_, double mass = 1.0, bool isDynamic_ = true, gdVec2 linearVelocity = gdVec2(0.0,0.0), gdVec2 acceleration = gdVec2(0.0,0.0) );
		~Planet();

		virtual bool OnCreate();
		virtual void OnDestroy();
		virtual void Update(double timestep);
		virtual void Render();
};