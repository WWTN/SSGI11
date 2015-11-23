#include "Asteroid.h"
#include "cocostudio/CocoStudio.h"

Asteroid::Asteroid()
{
	velocity = Vec2(1,0);
	this->init();
}


Asteroid::~Asteroid()
{

}

void Asteroid::init()
{
	_sprite = Sprite::create("Asteroid.png");
	_sprite->setPosition(0.5, 0.5);
}

void Asteroid::UpdateTrajectory(float endX, float endY)
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

cocos2d::Sprite* Asteroid::GetSprite()
{
	if (_sprite != nullptr)
		return _sprite;
	return nullptr;
}

void Asteroid::CollisionWithAsteroid()
{
	//if (this->getBoundingBox())
}