#pragma once
#include "HelloWorldScene.h"
#include "cocos2d.h"

// Override set position and call from constructor

class Asteroid : public cocos2d::Node
{
public:
	Asteroid();
	~Asteroid();

	//Setters
	void SetSprite();

	// Useful methods
	static Asteroid* create();
	void UpdateTrajectory(float endX, float endY);
	void Reset();
	void CollisionWithAsteroid();
	virtual bool init() override;
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
	cocos2d::Node* _rootNode;
};

