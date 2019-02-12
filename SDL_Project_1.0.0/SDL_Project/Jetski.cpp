#include "Jetski.h"
#include <SDL_image.h>



Jetski::Jetski(Matrix4 projMat_, SDL_Window* window_, std::string imageName_, gdVec2 position_, bool isDynamic_, gdVec2 linearVelocity) {

	projectionMatrix = projMat_;
	window = window_;

	imageName = imageName_;

	body = new gdBody(position_, linearVelocity, gdVec2(0.0, 0.0),  1.0,  isDynamic_);

	body->position = position_;

	OnCreate();


}


Jetski::~Jetski() {
	delete body;
	body = nullptr;

	delete image;
	image = nullptr;
	window = nullptr;


}


bool Jetski::OnCreate() {

	image = IMG_Load(imageName.c_str());
	if (image == nullptr) {
		return false;
	}


	rect.h = image->h;
	rect.w = image->w;
	rect.x = body->position.x;
	rect.y = body->position.y;
	return true;
}


void Jetski::OnDestroy() {

}
void Jetski::Update(double timestep) {

	body->Update(timestep);

}
void Jetski::Render() {
	Vec3 screenCoords = projectionMatrix * Vec3(body->position.x, body->position.y, 0.0f);


	rect.x = screenCoords.x;
	rect.y = screenCoords.y;


	SDL_BlitSurface(image, nullptr, SDL_GetWindowSurface(window), &rect);

}