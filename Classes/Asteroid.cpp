#include "Asteroid.h"
#include "cocostudio/CocoStudio.h"

using namespace cocos2d;

Asteroid* Asteroid::create()
{
	Asteroid* something = new Asteroid();
	if (something->init())
	{
		something->autorelease();
		return something;
	}
	else
	{
		CC_SAFE_DELETE(something);
		return nullptr;
	}
	return something;
}

bool Asteroid::init()
{
	if (!Node::init())
	{
		return false;
	}
	auto _rootNode = CSLoader::createNode("Asteroid.csb");
	addChild(_rootNode);


	auto winSize = Director::getInstance()->getVisibleSize();
	this->setPosition(Vec2(0.0f, winSize.height));
	this->setAnchorPoint(Vec2(winSize.width / 2, winSize.height / 2));
	this->scheduleUpdate();


	_sprite = (Sprite*)_rootNode->getChildByName("Asteroid_1");
	_sprite->setPosition(0.5, 0.5);
	return true;
}

Asteroid::Asteroid()
{
	velocity = Vec2(1,0);
	this->init();
}


Asteroid::~Asteroid()
{

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