#pragma once
#include "HelloWorldScene.h"
#include "cocos2d.h"

using namespace cocos2d;

class Asteroid : public cocos2d::Sprite , public cocos2d::Node
{
public:
	Asteroid(float startX, float startY);
	~Asteroid();

	//Setters
	void SetSprite(cocos2d::Sprite* sprite);

	// Useful methods
	void GenerateTrajectory(float endX, float endY);
	void Reset();
	virtual void Update(float);
	void CollisionWithAsteroid();

	// Start values
	Vec2 startPoint;
	Vec2 velocity;
private:
	cocos2d::Sprite* _sprite;
};

