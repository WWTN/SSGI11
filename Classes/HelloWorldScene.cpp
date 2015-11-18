#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"


USING_NS_CC;

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

	

	Sprite* asteroidSprite = (Sprite*)rootNode->getChildByName("Asteroid_1");
	Asteroid* _asteroid1 = new Asteroid(winSize.width*0.5, winSize.height*0.5);
	
	// Currently for example, remove vec2 later
	Vec2 myPos = Vec2(12, 12);
	_asteroid1->setPosition(myPos);
	_asteroid1->SetSprite(asteroidSprite);
	Asteroid* _asteroid2 = new Asteroid(2.0f, 2.0f);
	_asteroid2->SetSprite(asteroidSprite);
	Asteroid* _asteroid3 = new Asteroid(3.0f, 3.0f);
	_asteroid3->SetSprite(asteroidSprite);

    return true;
}

void HelloWorld::update(float deltaTime)
{

}