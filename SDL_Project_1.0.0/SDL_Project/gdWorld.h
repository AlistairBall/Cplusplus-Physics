#pragma once
#include "gdBody.h"
#include <vector>
#include "VMath.h"
#include "Vector.h"


using namespace MATH;

class gdWorld {
	

private:
	//create  vector of bodies
	std::vector<gdBody*> bodies;
	double elapsedTime;
	//0.0167 seconds per frame
	double timestep = 0.0167;
	gdVec2 gravityAcceleration = gdVec2(0.0, 0.0);
	gdVec2 windForce = gdVec2(0.0, 0.0);

public:
	gdWorld(gdVec2 & initialGravityAcceleration = gdVec2(0.0, 0.0), gdVec2 & initialWindForce = gdVec2(0.0, 0.0)) {
		gravityAcceleration = initialGravityAcceleration;
		windForce = initialWindForce;
		elapsedTime = 0.0;
	}

	void Update(double deltaTime) {


		for (int i = 0; i < bodies.size(); i++) {

		

			if (bodies[i]->position.x <= 0) {

				bodies[i]->linearVelocity.x *= -1;
			}
			if (bodies[i]->position.x >= 90) {

				bodies[i]->linearVelocity.x *= -1;
			}
			if (bodies[i]->position.y >= 5) {

				bodies[i]->linearVelocity.y *= -1;
			}
			if (bodies[i]->position.y <= 50) {

				bodies[i]->linearVelocity.y *= -1;
			}
		}


		for (int i = 0; i < bodies.size(); i++) {
		
			//only apply to bodies that are moving
			if (bodies[i]->isDynamic == true) {

			//	for (auto body : bodies) {

				for (int j = i + 1; j < bodies.size(); j++) {
					
						if (bodies[j] != bodies[i]) {




							//find distance  between planet and star
							gdVec2 dist = bodies[j]->position - bodies[i]->position;


							float mag = sqrt((dist.x * dist.x) + (dist.y * dist.y));

							//Big G is here|
							float force = (1 * bodies[j]->mass * bodies[i]->mass) / (mag * mag);

							gdVec2 normal = dist / mag;

							bodies[i]->ApplyForceToCentre(normal * force);




							
						/*	if (bodies[i]->linearVelocity.x < -20 || bodies[j]->linearVelocity.x < 20) {
								bodies[i]->linearVelocity.x = -20;
								bodies[j]->linearVelocity.x = -20;
							}
							if (bodies[i]->linearVelocity.y < -20 || bodies[j]->linearVelocity.y  < -20) {
								bodies[i]->linearVelocity.y = -20;
								bodies[j]->linearVelocity.y = -20;
							}*/




							if (bodies[j]->isDynamic == true) {

							Vec3 Normal = Vec3(bodies[i]->ballCentre.x - bodies[j]->ballCentre.x, bodies[i]->ballCentre.y - bodies[j]->ballCentre.y, 0);

							float distance = sqrt((Normal.x * Normal.x) + (Normal.y * Normal.y));

							float overlap = (bodies[i]->ballRadius + bodies[j]->ballRadius) - distance;
							//if collide
							if(overlap >= 0)
							{

								//dont let the balls get too fast
								if (bodies[i]->linearVelocity.x >= 50 || bodies[j]->linearVelocity.x >= 50) {
									bodies[i]->linearVelocity.x = 20;
									bodies[j]->linearVelocity.x = 20;
								}
								if (bodies[i]->linearVelocity.y >= 50 || bodies[j]->linearVelocity.y >= 50) {
									bodies[i]->linearVelocity.y = 20;
									bodies[j]->linearVelocity.y = 20;
								}

								// print velocity
								std::cout <<"X:" << bodies[i]->linearVelocity.x <<  std::endl;
								std::cout << "Y:" << bodies[i]->linearVelocity.x << std::endl;
								
								

								VMath math;
								if (Normal != Vec3()) {
									//normalize 
									Normal = math.normalize(Normal);
								}
								bodies[i]->position += gdVec2(Normal.x, Normal.y) * overlap;

								//convert Vec2 to Vec3
								Vec3 ballVelocity = Vec3(bodies[j]->linearVelocity.x, bodies[j]->linearVelocity.y, 0);
								Vec3 ballVelocity2 = Vec3(bodies[i]->linearVelocity.x, bodies[i]->linearVelocity.y, 0);

								//dot product
								Vec3 VoneP = math.dot(ballVelocity, Normal);
								Vec3 VtwoP = math.dot(ballVelocity2, Normal);

								//scotts equation  v1P = v1P(m1 - em2) + m2V2P(1 + e) 
								//----------------------------------------------------
								//                   m1 + m2

								Vec3 VonePrime = (VoneP * (bodies[j]->mass - (bodies[j]->bounce * bodies[i]->mass)) + (VtwoP * bodies[i]->mass*(1 + bodies[j]->bounce))) / (bodies[j]->mass + bodies[i]->mass);
								Vec3 VtwoPrime = (VtwoP * (bodies[i]->mass - (bodies[i]->bounce * bodies[j]->mass)) + (VoneP * bodies[j]->mass*(1 + bodies[i]->bounce))) / (bodies[i]->mass + bodies[j]->mass);

								bodies[j]->linearVelocity = bodies[j]->linearVelocity + math.dot((VonePrime - VoneP), Normal);

								bodies[i]->linearVelocity = bodies[i]->linearVelocity + math.dot((VtwoPrime - VtwoP), Normal);

							

							

							}




						}
					
						

						
					}
			}

			bodies[i]->Update(deltaTime);//And finally runs the update method with everything taken into account.
			}
		}
		elapsedTime += timestep;
	}

	void addBody(gdBody* body) {
		bodies.push_back(body);
	}

	void removeBody(gdBody * body) {
		bodies.pop_back();
	}

	~gdWorld() {
		for (gdBody * body : bodies) {
			delete body;
		}
	}
};