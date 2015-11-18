#include "Asteroid.h"
#include "cocostudio/CocoStudio.h"

Asteroid::Asteroid(float startX, float startY)
{
	//Create starpoint as asteroid is created
	startPoint = Vec2(startX, startY);
	velocity = Vec2(1,0);
}


Asteroid::~Asteroid()
{
}

void Asteroid::GenerateTrajectory(float endX, float endY)
{
	// Store endpoint
	Vec2 endPoint = Vec2(endX, endY);	

	// Find trajectory vector
	Vec2 trajectory = Vec2(endPoint - startPoint);
	trajectory.normalize();
	
	velocity = trajectory;
	
}

void Asteroid::Update(float deltaTime)
{
	

}
void Asteroid::SetSprite(cocos2d::Sprite* sprite)
{
	_sprite = sprite;
}