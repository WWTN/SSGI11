#pragma once
#include "HelloWorldScene.h"
#include "cocos2d.h"

using namespace cocos2d;

// Override set position and call from constructor

class Asteroid
{
public:
	Asteroid();
	~Asteroid();

	//Setters
	void SetSprite();

	// Useful methods
	void UpdateTrajectory(float endX, float endY);
	void Reset();
	void CollisionWithAsteroid();
	void init();
	//virtual Create();
	// may be removed
	virtual void Update(float);
	
	float currentPosX;

	cocos2d::Sprite* GetSprite();
	// Start values
	Vec2 startPoint;
	Vec2 velocity;

private:
	cocos2d::Sprite* _sprite;

};

