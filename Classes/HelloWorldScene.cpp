#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"


USING_NS_CC;

Asteroid* _asteroid1;
Asteroid* _astObject;

using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto rootNode = CSLoader::createNode("MainScene.csb");

    addChild(rootNode);

	this->scheduleUpdate();

	auto winSize = Director::getInstance()->getVisibleSize();

	// Set Sprite to be used
	_astObject = new Asteroid();
	this->addChild(_astObject->GetSprite());
	//Asteroid* _asteroid1 = new Asteroid();
	//_asteroid1->getSprite()->setPosition(Vec2(winSize.width/2,winSize.height/2));
	//_asteroid1 = _asteroid1->create("Asteroid.png");

	//_asteroid1->SetSprite("Asteroid.png");

	//rootNode->addChild(_asteroid1);
	
	// Currently for test, remove vec2 later
	
	
	//Asteroid* _asteroid2 = new Asteroid(2.0f, 2.0f);
	//_asteroid2->SetSprite(asteroidSprite);
	//Asteroid* _asteroid3 = new Asteroid(3.0f, 3.0f);
	//_asteroid3->SetSprite(asteroidSprite);

	//this->addChild(_asteroid1);

	// Touch listener init
	auto touchListener = EventListenerTouchOneByOne::create();
	// Callbacks for touch
	touchListener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
	touchListener->onTouchCancelled = CC_CALLBACK_2(HelloWorld::onTouchCancelled, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
	this->scheduleUpdate();
    return true;
}

void HelloWorld::update(float delta)
{
	//_asteroid1->setPositionX(_asteroid1->currentPosX() + 1);
	//Vec2 myPos = Vec2(20, 20);
	//_asteroid1->setPosition(myPos);
	_astObject->GetSprite()->setPosition(Vec2(_asteroid1->GetSprite()->getPosition().x + 1, _asteroid1->GetSprite()->getPosition().y + 1));
}

bool HelloWorld::onTouchBegan(Touch* touch, Event* event)
{
	cocos2d::log("touch began");
	return true;
}

void HelloWorld::onTouchEnded(Touch* touch, Event* event)
{

}
void HelloWorld::onTouchMoved(Touch* touch, Event* event)
{

}
void HelloWorld::onTouchCancelled(Touch* touch, Event* event)
{

}