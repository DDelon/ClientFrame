#include "HelloWorldScene.h"
#include "ui/CocosGUI.h"
#include "SimpleAudioEngine.h"
#include "ECS/SystemManager.h"
#include "ECS/TimeSystem.h"
#include "ECS/MoveSystem.h"
#include "ECS/RenderSystem.h"
#include "ECS/EntityCreator.h"
#include "ECS/EntityManager.h"
#include "ECS/InputSystem.h"
#include "ECS/CheckToBaseSystem.h"
#include "ECS/CreatorSystem.h"
#include "ECS/WriteToMapSystem.h"
#include "GameInfo.h"

USING_NS_CC;

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
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	EntityManager::getInstance()->registerComponents(7);

	//EntityCreator::createRectShape();
	EntityCreator::createSquare();
	//InputSystem->MoveSystem->CheckToBaseSystem->WriteToMapSystem->TimeSystem->RenderSystem->CreatorSystem
	//
	InputSystem *pInputSys = new InputSystem(1);
	SystemManager::getInstance()->addSystem(pInputSys);

	MoveSystem *pMoveSys = new MoveSystem(2);
	SystemManager::getInstance()->addSystem(pMoveSys);

	CheckToBaseSystem *pCheckSys = new CheckToBaseSystem(3);
	SystemManager::getInstance()->addSystem(pCheckSys);

	WriteToMapSystem *pWriteToMapSys = new WriteToMapSystem(4);
	SystemManager::getInstance()->addSystem(pWriteToMapSys);

	TimeSystem *pTimeSys = new TimeSystem(5);
	SystemManager::getInstance()->addSystem(pTimeSys);

	RenderSystem *pRenderSys = new RenderSystem(6, this);
	SystemManager::getInstance()->addSystem(pRenderSys);

	CreatorSystem *pCreatorSys = new CreatorSystem(7);
	SystemManager::getInstance()->addSystem(pCreatorSys);



    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);

	this->scheduleUpdate();

	ui::Button *pLeft = static_cast<ui::Button *>(ui::Button::createInstance());
	pLeft->setTouchEnabled(true);
	pLeft->setTitleFontSize(25);
	pLeft->setTitleText("Left");
	pLeft->setPosition(Vec2(50, 100));
	pLeft->addTouchEventListener([=](Ref *pSender, ui::Widget::TouchEventType touchEvt){
		if (touchEvt == ui::Widget::TouchEventType::BEGAN)
		{
			GameInfo::getInstance()->setKeyCode(ECS::DirectionComponent::LEFT);
		}
		else if (touchEvt == ui::Widget::TouchEventType::ENDED)
		{
			GameInfo::getInstance()->setKeyCode(ECS::DirectionComponent::NONE);
		}
	});
	this->addChild(pLeft);

	ui::Button *pRight = static_cast<ui::Button *>(ui::Button::createInstance());
	pRight->setTouchEnabled(true);
	pRight->setTitleFontSize(25);
	pRight->setTitleText("Right");
	pRight->setPosition(Vec2(150, 100));
	pRight->addTouchEventListener([=](Ref *pSender, ui::Widget::TouchEventType touchEvt){
		if (touchEvt == ui::Widget::TouchEventType::BEGAN)
		{
			GameInfo::getInstance()->setKeyCode(ECS::DirectionComponent::RIGHT);
		}
		else if (touchEvt == ui::Widget::TouchEventType::ENDED)
		{
			GameInfo::getInstance()->setKeyCode(ECS::DirectionComponent::NONE);
		}
	});
	this->addChild(pRight);

	ui::Button *pUp = static_cast<ui::Button *>(ui::Button::createInstance());
	pUp->setTouchEnabled(true);
	pUp->setTitleFontSize(25);
	pUp->setTitleText("UP");
	pUp->setPosition(Vec2(100, 150));
	pUp->addTouchEventListener([=](Ref *pSender, ui::Widget::TouchEventType touchEvt){
		if (touchEvt == ui::Widget::TouchEventType::BEGAN)
		{
			GameInfo::getInstance()->setKeyCode(ECS::DirectionComponent::UP);
		}
		else if (touchEvt == ui::Widget::TouchEventType::ENDED)
		{
			GameInfo::getInstance()->setKeyCode(ECS::DirectionComponent::NONE);
		}
	});
	this->addChild(pUp);

	ui::Button *pDown = static_cast<ui::Button *>(ui::Button::createInstance());
	pDown->setTouchEnabled(true);
	//pDown->setScale9Enabled(true);
	pDown->setTitleFontSize(25);
	pDown->setTitleText("Left");
	pDown->setPosition(Vec2(100, 50));
	pDown->addTouchEventListener([=](Ref *pSender, ui::Widget::TouchEventType touchEvt){
		if (touchEvt == ui::Widget::TouchEventType::BEGAN)
		{
			GameInfo::getInstance()->setKeyCode(ECS::DirectionComponent::DOWN);
		}
		else if (touchEvt == ui::Widget::TouchEventType::ENDED)
		{
			GameInfo::getInstance()->setKeyCode(ECS::DirectionComponent::NONE);
		}
	});
	this->addChild(pDown);

	ui::Button *pPause = static_cast<ui::Button *>(ui::Button::createInstance());
	pPause->setTouchEnabled(true);
	pPause->setTitleFontSize(25);
	pPause->setTitleText("Pause");
	pPause->setPosition(Vec2(540, 50));
	pPause->addTouchEventListener([=](Ref *pSender, ui::Widget::TouchEventType touchEvt){
		if (touchEvt == ui::Widget::TouchEventType::BEGAN)
		{
			SystemManager::getInstance()->setPause(!SystemManager::getInstance()->isPause());
		}
		else if (touchEvt == ui::Widget::TouchEventType::ENDED)
		{
			
		}
	});
	this->addChild(pPause);



	
    
    return true;
}

void HelloWorld::update(float dt)
{
	SystemManager::getInstance()->update(dt);
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
    
    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
    
    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
    
    
}
