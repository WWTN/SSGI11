#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class HelloWorld : public cocos2d::Layer
{
public:

	//Variables used in the game
	bool StartButtonPressed();


    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

	// Update function, because otherwise it wouldn't
	void update(float);

	 bool getTouchTarget();
	 virtual bool onTouchBegan(cocos2d::Touch*, cocos2d::Event*);
	 virtual void onTouchEnded(cocos2d::Touch*, cocos2d::Event*);
	 virtual void onTouchMoved(cocos2d::Touch*, cocos2d::Event*);
	 virtual void onTouchCancelled(cocos2d::Touch*, cocos2d::Event*);
	 cocos2d::Sprite*        game_Ship;
	
	 //Okay, I might not need these right this second but I don't want to not have them later if I do end up needing them. It's messey but saving time is good
		//?)
    // implement the "static create()" method manually
//	 game_player* obj = new game_player;
	 void    moveToActivePointBeta();

    CREATE_FUNC(HelloWorld);

private:
	
	cocos2d::Sprite*        invisibleTarget;

	cocos2d::Sprite*        visibleTarget;
	cocos2d::ui::Button*    startButton;
	bool targetingOnline;
	
};

#endif // __HELLOWORLD_SCENE_H__
