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
		
	//	game_player obj;

	//-----------------------------------------------------
		//get references to stuff needed
		
		game_Ship = (Sprite*)rootNode->getChildByName("game_Ship");
		invisibleTarget = (Sprite*)rootNode->getChildByName("invisibleTarget");

		visibleTarget = (Sprite*)rootNode->getChildByName("visibleTarget");

			

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
	startButton = static_cast<ui::Button*>(rootNode->getChildByName("temp_Go"));	/*
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
void HelloWorld::onTouchMoved(Touch* touch, Event* event)
{
	if(targetingOnline){
		visibleTarget->setPosition(touch->getLocation()); }
}
void HelloWorld::onTouchCancelled(Touch* touch, Event* event)
{
	
}
void HelloWorld::onTouchEnded(Touch* touch, Event* event)
{
	targetingOnline = false;
}

bool HelloWorld::onTouchBegan(Touch* touch, Event* event)
{
	invisibleTarget->setPosition(touch->getLocation());
//	if (obj->withinBoundingBox( game_Ship, invisibleTarget) )
	{
		targetingOnline = true;
	}


	//game_Ship->setPosition(touch->getLocation());
//	labelTouchInfo->setString("You Touched Here");
	return true;
}



/* ->setPosition(touch->getLocation());
bool HelloWorld::getTouchTarget(Touch* touch)
{
	
		touchToPoint(touch));

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
/*
void HelloWorld::moveToActivePointBeta()
{
	if (game_Ship->getPositionX > visibleTarget->getPositionX)
	{(game_Ship->setPositionX = game_Ship->getPositionX - 0.5)}


	if (game_Ship->getPositionY > visibleTarget->getPositionY)
	{
		(game_Ship->setPositionY = game_Ship->getPositionY - 0.5)
	}




}
*/