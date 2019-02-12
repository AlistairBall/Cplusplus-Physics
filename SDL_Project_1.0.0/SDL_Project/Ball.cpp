#include "Ball.h"
#include "MMath.h"
#include "Matrix.h"
#include <SDL_image.h>



Ball::Ball(Matrix4 projMat_, SDL_Window* window_, std::string imageName_, gdVec2 position_, double mass, bool isDynamic_, gdVec2 linearVelocity, gdVec2 acceleration) {

	projectionMatrix = projMat_;
	window = window_;

	imageName = imageName_;

	gdVec2 pause = position_;

	//if statements to ensure that the balls dont spawn too close to the sun
	if (abs(position_.x - 46) <= 5) {
		
		//if position - 46 is greater than zero then add ten, if not - 10.
		pause.x += position_.x - 46 >= 0 ? 10 : -10;
	}

	if (abs(position_.y - 28) <= 5) {
		pause.y += position_.y -28 >= 0 ? 10 : -10;
	}
	


	body = new gdBody(pause, linearVelocity, acceleration, mass, isDynamic_);

	body->position = pause;

	

	OnCreate();


}


Ball::~Ball() {
	delete body;
	body = nullptr;

	delete image;
	image = nullptr;
	window = nullptr;


}


bool Ball::OnCreate() {

	image = IMG_Load(imageName.c_str());
	std::cout << IMG_GetError() << std::endl;
	if (image == nullptr) {
		return false;
	}


	rect.h = image->h;
	rect.w = image->w;
	rect.x = body->position.x;
	rect.y = body->position.y;

	Matrix4 projection = MMath::viewportNDC(1000, 600) * (MMath::orthographic(0.0f, 100.0f, 0.0f, 50.0f, 0.0f, 1.0f));
	Vec4 tempRadius = MMath::inverse(projection) * Vec4((rect.w / 2.0f), 0,0,1);
	tempRadius.w = 1.0f / tempRadius.w;
	tempRadius.x *= tempRadius.w;
	body->ballRadius = tempRadius.x;
	Vec4 tempPosition = MMath::inverse(projection) * Vec4(rect.x, rect.y, 0, 1);
	tempPosition.w = 1.0f / tempPosition.w;
	tempPosition.y = 1.0f / tempPosition.y;
	tempPosition.x = 1.0f / tempPosition.x;
	body->ballCentre = gdVec2(tempPosition.x + body->ballRadius, tempPosition.y + body->ballRadius);
	body->bounce = 0.1f;
	return true;
}


void Ball::OnDestroy() {

}
void Ball::Update(double timestep) {

}
void Ball::Render() {

	body->ballCentre = gdVec2(body->position.x + body->ballRadius, body->position.y + body->ballRadius);

	Vec3 screenCoords = projectionMatrix * Vec3(body->position.x, body->position.y, 0.0f);


	rect.x = screenCoords.x;
	rect.y = screenCoords.y;


	SDL_BlitSurface(image, nullptr, SDL_GetWindowSurface(window), &rect);

	

}