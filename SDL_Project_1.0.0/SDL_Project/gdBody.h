#pragma once
#include "gdVec2.h"
#include <math.h>
#include <stdio.h>
#include <iostream>


struct gdBody {

	double mass;
	gdVec2 position;
	gdVec2 linearVelocity;
	gdVec2 acceleration;
	bool isDynamic;
	float ballRadius;
	gdVec2 ballCentre;
	float bounce;

	gdBody(gdVec2 position, gdVec2 linearVelocity, gdVec2 acceleration = gdVec2(0.0, 0.0), double mass = 1.0, bool isDynamic_ = true) : position(position), linearVelocity(linearVelocity), acceleration(acceleration), mass(mass), isDynamic(isDynamic_)
	{

	}

	gdBody(double mass, bool isDynamic_ = true) : mass(mass) {
		linearVelocity.SetZero();
		position.SetZero();
		acceleration.SetZero();
	}

	void ApplyForceToCentre(gdVec2 & force) {//update acceleration using a=f/m
		acceleration += (force / mass);
	}

	void Update(double timestep){

		if(timestep != 0){
			if (isDynamic) {
				linearVelocity += (acceleration * timestep); //The Formula for linear velocity updates 
				position += (linearVelocity * timestep) + (acceleration * 0.5) * (timestep*timestep);//The Formula for position updates
				acceleration.SetZero();
			}
		}
	}



};