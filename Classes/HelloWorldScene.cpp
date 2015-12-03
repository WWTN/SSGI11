#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "game_player.h"
#include "GameManager.h"

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
	// Initialisation
	if (!Layer::init())
	{
		return false;
	}

	auto rootNode = CSLoader::createNode("MainScene.csb");

	addChild(rootNode);

		this->scheduleUpdate();
	
		auto winSize = Director::getInstance()->getVisibleSize();


	//-----------------------------------------------------
		//get references to stuff needed
		
		game_Ship = (Sprite*)rootNode->getChildByName("game_Ship");
			

	//-----------------------------------------------------------------------------------------
	//TOUCHES
	//Set up a touch listener.
	auto touchListener = EventListenerTouchOneByOne::create();


	//Set callbacks for our touch functions.
	touchListener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
	touchListener->onTouchCancelled = CC_CALLBACK_2(HelloWorld::onTouchCancelled, this);

	//Add our touch listener to event listener list.
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);


		//-----------------------------------------------------------------------------------------
		//Start button.
/*		startButton = static_cast<ui::Button*>(rootNode->getChildByName("temp_Go"));
		startButton->addTouchEventListener(CC_CALLBACK_2(HelloWorld::StartButtonPressed, this));
		startButton->setPosition(Vec2(winSize.width*0.5f, winSize.height*0.5f));
		//-----------------------------------------------------------------------------------------*/

	return true;


}
void HelloWorld::update(float delta)
{
	if (GameManager::sharedGameManager()->isGameLive)
	{

	}
}

/*
bool MyLayer::isTouchingSprite(Touch* touch)
{
	// this works by calculating the distance between the sprite's
	// center and the touch point, then seeing if that distance is
	// less than the sprite's radius
	float distance = this->sprite->getPosition().getDistance(
		this->touchToPoint(touch));
	return (distance < 100.0f);
}
*/
//}
////
////addChild(rootNode);
//
//// on "init" you need to initialize your instance
//bool HelloWorld::init()
//{
//	//////////////////////////////
//	// 1. super init first
//	if (!Layer::init())
//	{
//		return false;
//	}
//
//	auto rootNode = CSLoader::createNode("MainScene.csb");
//
//	addChild(rootNode);
//
//	this->scheduleUpdate();
//
//	auto winSize = Director::getInstance()->getVisibleSize();
//	//Get the objects that we need references to in order to move them.
//	upForce = 0;
//	flappyBird = (Sprite*)rootNode->getChildByName("flappyBird");
//
//	//Score label.
//	scoreLabel = (Label*)rootNode->getChildByName("scoreLabel");
//
//	//pipes = (Pipe*)rootNode->getChildByName("pipes");
//	pipes = Pipe::create();
//	this->addChild(pipes);
//
//	//-----------------------------------------------------------------------------------------
//	//TOUCHES
//	//Set up a touch listener.
//	auto touchListener = EventListenerTouchOneByOne::create();
//
//	//Set callbacks for our touch functions.
//	touchListener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
//	touchListener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);
//	touchListener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
//	touchListener->onTouchCancelled = CC_CALLBACK_2(HelloWorld::onTouchCancelled, this);
//
//	//Add our touch listener to event listener list.
//	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
//	//-----------------------------------------------------------------------------------------
//
//
//	// Game is not live until the start button is pressed.
//	GameManager::sharedGameManager()->isGameLive = false;
//
//	return true;
//}