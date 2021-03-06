#include "EntityCreator.h"
#include "Component.h"
#include "EntityManager.h"
#include "GameInfo.h"
using namespace ECS;

EntityCreator::EntityCreator()
{
}

EntityCreator::~EntityCreator()
{
}

unsigned int EntityCreator::createRectShape()
{
	int entityId = EntityManager::getInstance()->createEntity();
	Size winSize = Director::getInstance()->getWinSize();
	
	//渲染组件
	RenderComponent *pRender = new RenderComponent();
	pRender->_pBlockLayer = LayerColor::create(Color4B(100, 100, 100, 100));
	pRender->_pBlockLayer->setPosition(Vec2(winSize.width / 2, winSize.height));
	pRender->_pBlockLayer->retain();

	//创建4个块
	for (int i = 0; i < 4; ++i)
	{
		Sprite *pBlock = Sprite::create("block1.png");
		pRender->_pBlockLayer->addChild(pBlock);
	}
	Vector<Node *> childrenVec = pRender->_pBlockLayer->getChildren();
	Size size = childrenVec.at(0)->getContentSize();
	//排列形状
	childrenVec.at(0)->setPosition(Vec2(-size.width-size.width/2, size.height/2));
	for (int i = 1; i < childrenVec.size(); ++i)
	{
		childrenVec.at(i)->setPosition(Vec2(childrenVec.at(i-1)->getPositionX()+size.width, childrenVec.at(i-1)->getPositionY()));
	}
	pRender->_pBlockLayer->setContentSize(Size(size.width*4, size.height));
	EntityManager::getInstance()->addComponent(pRender, RENDER_COMPONENT, entityId);

	//位置组件
	PositionComponent *pPosition = new PositionComponent();
	pPosition->_x = winSize.width / 2;
	pPosition->_y = winSize.height;
	EntityManager::getInstance()->addComponent(pPosition, POSITION_COMPONENT, entityId);

	//速度组件
	SpeedComponent *pSpeed = new SpeedComponent();
	pSpeed->_speedX = size.width;
	pSpeed->_speedY = size.height;
	EntityManager::getInstance()->addComponent(pSpeed, SPEED_COMPONENT, entityId);

	//计时组件
	TimeComponent *pTime = new TimeComponent(1);
	EntityManager::getInstance()->addComponent(pTime, TIME_COMPONENT, entityId);

	//类型组件
	EntityTypeComponent *pEntityType = new EntityTypeComponent();
	pEntityType->_type = EntityTypeComponent::RECT_ANGLE;
	EntityManager::getInstance()->addComponent(pEntityType, ENTITY_TYPE_COMPONENT, entityId);

	//方向组件
	DirectionComponent *pDirection = new DirectionComponent();
	pDirection->_direction = DirectionComponent::DOWN;
	EntityManager::getInstance()->addComponent(pDirection, DIRECTION_COMPONENT, entityId);

	//状态组件
	StatusComponent *pStatus = new StatusComponent();
	pStatus->_status = StatusComponent::FALL;
	EntityManager::getInstance()->addComponent(pStatus, STATUS_COMPONENT, entityId);

	return entityId;
}

unsigned int EntityCreator::createSquare()
{
	int entityId = EntityManager::getInstance()->createEntity();
	Size winSize = Director::getInstance()->getWinSize();

	//渲染组件
	RenderComponent *pRender = new RenderComponent();
	pRender->_pBlockLayer = LayerColor::create(Color4B(100, 100, 100, 100));
	pRender->_pBlockLayer->setPosition(Vec2(winSize.width / 2, winSize.height));
	pRender->_pBlockLayer->retain();

	//创建4个块
	for (int i = 0; i < 4; ++i)
	{
		Sprite *pBlock = Sprite::create("block1.png");
		pRender->_pBlockLayer->addChild(pBlock);
	}
	Vector<Node *> childrenVec = pRender->_pBlockLayer->getChildren();
	Size size = childrenVec.at(0)->getContentSize();
	log("create square size width:%f height:%f", size.width, size.height);
	//排列形状
	childrenVec.at(0)->setPosition(Vec2(-size.width / 2, size.height / 2));
	childrenVec.at(1)->setPosition(Vec2(size.width / 2, size.height / 2));
	childrenVec.at(2)->setPosition(Vec2(-size.width / 2, size.height + size.height / 2));
	childrenVec.at(3)->setPosition(Vec2(size.width / 2, size.height + size.height / 2));
	pRender->_pBlockLayer->setContentSize(Size(size.width * 2, size.height * 2));

	EntityManager::getInstance()->addComponent(pRender, RENDER_COMPONENT, entityId);

	//位置组件
	PositionComponent *pPosition = new PositionComponent();
	pPosition->_x = winSize.width/2;
	pPosition->_y = winSize.height;
	EntityManager::getInstance()->addComponent(pPosition, POSITION_COMPONENT, entityId);

	//速度组件
	SpeedComponent *pSpeed = new SpeedComponent();
	pSpeed->_speedX = size.width;
	pSpeed->_speedY = size.height;
	EntityManager::getInstance()->addComponent(pSpeed, SPEED_COMPONENT, entityId);

	//计时组件
	TimeComponent *pTime = new TimeComponent(0.8);
	EntityManager::getInstance()->addComponent(pTime, TIME_COMPONENT, entityId);

	//类型组件
	EntityTypeComponent *pEntityType = new EntityTypeComponent();
	pEntityType->_type = EntityTypeComponent::SQUARE;
	EntityManager::getInstance()->addComponent(pEntityType, ENTITY_TYPE_COMPONENT, entityId);

	//方向组件
	DirectionComponent *pDirection = new DirectionComponent();
	pDirection->_direction = DirectionComponent::DOWN;
	EntityManager::getInstance()->addComponent(pDirection, DIRECTION_COMPONENT, entityId);

	//状态组件
	StatusComponent *pStatus = new StatusComponent();
	pStatus->_status = StatusComponent::FALL;
	EntityManager::getInstance()->addComponent(pStatus, STATUS_COMPONENT, entityId);


	return entityId;
}

unsigned int EntityCreator::createLShape()
{
	return 0;
}

unsigned int EntityCreator::createBlock(int row, int col)
{

	int entityId = EntityManager::getInstance()->createEntity();
	//渲染组件
	SpriteRenderComponent *pRender = new SpriteRenderComponent();
	pRender->_pSprite = Sprite::create("block4.png");
	pRender->_pSprite->retain();
	Size size = pRender->_pSprite->getContentSize();
	EntityManager::getInstance()->addComponent(pRender, SPRITERENDER_COMPONENT, entityId);


	//位置组件
	PositionComponent *pPosition = new PositionComponent();
	pPosition->_x = col*BLOCK_WIDTH - BLOCK_WIDTH/2;
	pPosition->_y = row*BLOCK_HEIGHT - BLOCK_HEIGHT/2;
	EntityManager::getInstance()->addComponent(pPosition, POSITION_COMPONENT, entityId);

	//速度组件
	SpeedComponent *pSpeed = new SpeedComponent();
	pSpeed->_speedX = size.width;
	pSpeed->_speedY = size.height;
	EntityManager::getInstance()->addComponent(pSpeed, SPEED_COMPONENT, entityId);

	//计时组件
	TimeComponent *pTime = new TimeComponent(0.8);
	EntityManager::getInstance()->addComponent(pTime, TIME_COMPONENT, entityId);

	//类型组件
	EntityTypeComponent *pEntityType = new EntityTypeComponent();
	pEntityType->_type = EntityTypeComponent::SQUARE;
	EntityManager::getInstance()->addComponent(pEntityType, ENTITY_TYPE_COMPONENT, entityId);

	//方向组件
	DirectionComponent *pDirection = new DirectionComponent();
	pDirection->_direction = DirectionComponent::DOWN;
	EntityManager::getInstance()->addComponent(pDirection, DIRECTION_COMPONENT, entityId);

	//状态组件
	StatusComponent *pStatus = new StatusComponent();
	pStatus->_status = StatusComponent::FALL;
	EntityManager::getInstance()->addComponent(pStatus, STATUS_COMPONENT, entityId);

	return entityId;
}