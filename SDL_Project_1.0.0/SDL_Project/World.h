//#pragma once
//#include "gdBody.h"
//#include <vector>
//#include "VMath.h"
//#include "Vector.h"
//#include "Scene0.h"
//
//
//using namespace MATH;
//
//class World {
//
//
//private:
//	//create  vector of bodies
//	std::vector<gdBody*> bodies;
//	double elapsedTime;
//	//0.0167 seconds per frame
//	double timestep = 0.0167;
//	gdVec2 gravityAcceleration = gdVec2(0.0, 0.0);
//	gdVec2 windForce = gdVec2(0.0, 0.0);
//
//public:
//	World(gdVec2 & initialGravityAcceleration = gdVec2(0.0, 0.0), gdVec2 & initialWindForce = gdVec2(0.0, 0.0)) {
//		gravityAcceleration = initialGravityAcceleration;
//		windForce = initialWindForce;
//		elapsedTime = 0.0;
//	}
//
//	void Update(double deltaTime) {
//		for (int i = 0; i < bodies.size(); i++) {
//
//			if (bodies[i]->position.x <= 0) {
//
//				bodies[i]->linearVelocity.x *= -1;
//			}
//			if (bodies[i]->position.x >= 90) {
//
//				bodies[i]->linearVelocity.x *= -1;
//			}
//			if (bodies[i]->position.y >= 5) {
//
//				bodies[i]->linearVelocity.y *= -1;
//			}
//			if (bodies[i]->position.y <= 50) {
//
//				bodies[i]->linearVelocity.y *= -1;
//			}
//		}
//
//		for (int i = 0; i < bodies.size(); i++) {
//
//			if (bodies[i]->isDynamic == true) {
//
//				//find distance  between planet and star
//				//	gdVec2 dist = bodies[j]->position - bodies[i]->position;
//				//float mag = sqrt((dist.x * dist.x) + (dist.y * dist.y));
//				////Big G is here|
//				//float force = (1 * bodies[j]->mass * bodies[i]->mass) / (mag * mag);
//
//				//gdVec2 normal = dist / mag;
//				//bodies[i]->ApplyForceToCentre(normal * force);
//
//				gdVec2 dist = bodies[i]->position - tmpPlanet2;
//				float mag = sqrt((dist.x * dist.x) + (dist.y * dist.y));
//				//Big G is here|
//				float force = (1 * bodies[j]->mass * bodies[i]->mass) / (mag * mag);
//				gdVec2 normal = dist / mag;
//				bodies[i]->ApplyForceToCentre(normal * force);
//
//
//
//			}
//
//		}
//		////only apply to bodies that are moving
//		//if (bodies[i]->isDynamic == true) {
//
//		////	for (auto body : bodies) {
//
//		//	for (int j = i + 1; j < bodies.size() ; j++) {
//		//		
//		//			if (bodies[j] != bodies[i]) {
//
//
//
//
//		//				if (bodies[j]->isDynamic == true) {
//
//		//				Vec3 Normal = Vec3(bodies[i]->ballCentre.x - bodies[j]->ballCentre.x, bodies[i]->ballCentre.y - bodies[j]->ballCentre.y, 0);
//
//		//				float distance = sqrt((Normal.x * Normal.x) + (Normal.y * Normal.y));
//
//		//				float overlap = (bodies[i]->ballRadius + bodies[j]->ballRadius) - distance;
//
//		//				if(overlap >= 0)
//		//				{
//
//		//					
//		//					std::cout <<"X:" << bodies[i]->linearVelocity.x <<  std::endl;
//		//					std::cout << "Y:" << bodies[i]->linearVelocity.y << std::endl;
//		//					
//		//					
//
//		//					VMath math;
//		//					if (Normal != Vec3()) {
//
//		//						Normal = math.normalize(Normal);
//		//					}
//		//					bodies[i]->position += gdVec2(Normal.x, Normal.y) * overlap;
//
//		//					Vec3 ballVelocity = Vec3(bodies[j]->linearVelocity.x, bodies[j]->linearVelocity.y, 0);
//		//					Vec3 ballVelocity2 = Vec3(bodies[i]->linearVelocity.x, bodies[i]->linearVelocity.y, 0);
//
//		//					Vec3 VoneP = math.dot(ballVelocity, Normal);
//		//					Vec3 VtwoP = math.dot(ballVelocity2, Normal);
//
//		//					Vec3 VonePrime = (VoneP * (bodies[j]->mass - (bodies[j]->bounce * bodies[i]->mass)) + VtwoP * bodies[i]->mass*(1 + bodies[j]->bounce)) / (bodies[j]->mass + bodies[i]->mass);
//		//					Vec3 VtwoPrime = (VtwoP * (bodies[i]->mass - (bodies[i]->bounce * bodies[j]->mass)) + VoneP * bodies[j]->mass*(1 + bodies[i]->bounce)) / (bodies[i]->mass + bodies[j]->mass);
//
//		//					bodies[j]->linearVelocity = bodies[j]->linearVelocity + math.dot((VonePrime - VoneP), Normal);
//
//		//					bodies[i]->linearVelocity = bodies[i]->linearVelocity + math.dot((VtwoPrime - VtwoP), Normal);
//
//		//				
//
//		//				}
//
//		//			
//
//		//				
//
//
//		//}
//
//		//				}
//
//		//			}
//		//		
//		//			
//
//		//			
//		//		}
//
//
//		//}
//
//		//bodies[i]->Update(deltaTime);//And finally runs the update method with everything taken into account.
//		//	}
//		//}
//		//elapsedTime += timestep;
//		//}
//
//		void addBody(gdBody* body) {
//			bodies.push_back(body);
//		}
//
//		void removeBody(gdBody * body) {
//			bodies.pop_back();
//		}
//
//		~World() {
//			for (gdBody * body : bodies) {
//				delete body;
//			}
//		}
//	};