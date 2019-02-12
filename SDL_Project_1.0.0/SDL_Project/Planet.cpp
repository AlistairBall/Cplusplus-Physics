#include "Planet.h"
#include "Matrix.h"
#include "MMath.h"
#include <SDL_image.h>



Planet::Planet(Matrix4 projMat_, SDL_Window* window_, std::string imageName_, gdVec2 position_, double mass, bool isDynamic_, gdVec2 linearVelocity, gdVec2 acceleration) {

	projectionMatrix = projMat_;
	window = window_;

	imageName = imageName_;

	body = new gdBody(position_, linearVelocity, acceleration, mass, isDynamic_);

	body->position = position_;

	OnCreate();
	

}


Planet::~Planet() {
	delete body;
	body = nullptr;

	delete image;
	image = nullptr;
	window = nullptr;


}


bool Planet::OnCreate() {

	image = IMG_Load(imageName.c_str());
	if (image == nullptr) {
		return false;
	}
	

	rect.h = image->h;
	rect.w = image->w;
	rect.x = body->position.x;
	rect.y = body->position.y;
	Matrix4 projection = MMath::viewportNDC(1000, 600) * (MMath::orthographic(0.0f, 100.0f, 0.0f, 50.0f, 0.0f, 1.0f));
	Vec4 tempRadius = MMath::inverse(projection) * Vec4((rect.w / 2.0f), 0, 0, 1);
	tempRadius.w = 1.0f / tempRadius.w;
	tempRadius.x *= tempRadius.w;
	body->ballRadius = tempRadius.x;
	Vec4 tempPosition = MMath::inverse(projection) * Vec4(rect.x, rect.y, 0, 1);
	tempPosition.w = 1.0f / tempPosition.w;
	tempPosition.y = 1.0f / tempPosition.y;
	tempPosition.x = 1.0f / tempPosition.x;
	body->ballCentre = gdVec2(tempPosition.x + body->ballRadius, tempPosition.y + body->ballRadius);
	body->bounce = 0.8f;
	return true;
}


void Planet::OnDestroy() {

}
void Planet::Update(double timestep) {

}
void Planet::Render() {

	Vec3 screenCoords = projectionMatrix * Vec3(body->position.x, body->position.y, 0.0f);


	rect.x = screenCoords.x;
	rect.y = screenCoords.y;


	SDL_BlitSurface(image, nullptr, SDL_GetWindowSurface(window), &rect);

	body->ballCentre = gdVec2(rect.x + body->ballRadius, rect.y + body->ballRadius);

}