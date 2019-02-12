#include "gdWorld.h"
#include "gdVec2.h"
#include "gdBody.h"



gdWorld::gdWorld(gdVec2& initialGravityAcceleration, gdVec2& initialWindForce)
{
	elapsedTime = 0.0;
	gravityAcceleration = initialGravityAcceleration;
	windForce = initialWindForce;


}

gdWorld::~gdWorld()
{
	for (gdBody* body : bodies)
	{
		delete body;
	}
}

void gdWorld::Update(double deltaTime)
{
	for (gdBody* body : bodies)
	{

		
		body->Update(deltaTime);



		




		/*

		//vf = vi + a * t
		body->linearVelocity = body->acceleration * deltaTime;

		//sf = si + v * t
		body->position += body->linearVelocity * deltaTime;

		body->acceleration.SetZero();

		*/
	}

	elapsedTime += deltaTime;
}
void gdWorld::AddBody(gdBody* body)
{
	bodies.push_back(body);
	
	
    body->ApplyForceToCenter(windForce);
	body->gravity = gravityAcceleration;
	
}

bool gdWorld::RemoveBody(gdBody* body)
{
	auto it = find(bodies.begin(), bodies.end(), body);

	if (it != bodies.end())
	{
		bodies.erase(it);
		return true;
	}
	return false;
}


