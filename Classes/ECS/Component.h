#ifndef __COMPONENT_H__
#define __COMPONENT_H__

#include "cocos2d.h"
USING_NS_CC;

#define RENDER_COMPONENT		(1 << 1)
#define POSITION_COMPONENT		(1 << 2)
#define ENTITY_TYPE_COMPONENT	(1 << 3)

namespace ECS
{
	class Component
	{
	public:
		Component() {}
		virtual ~Component() {}

	};

	class RenderComponent : public Component
	{
	public:
		RenderComponent(std::string fileName) 
		{
			_pBlockLayer = LayerColor::create(Color4B(100, 100, 100, 100));
			this->createBlock(4);
			
		}
		virtual ~RenderComponent()
		{
			_pBlockLayer->removeAllChildren();
			_pBlockLayer->removeFromParent();
		}

		bool isAdded() 
		{
			return !(_pBlockLayer->getParent() == nullptr);
		}

		void addToParent(Node *pParent)
		{
			pParent->addChild(_pBlockLayer);
		}

	private:
		void createBlock(int num)
		{
			for (int i = 0; i < num; ++i)
			{
				Sprite *pBlock = Sprite::create("block1.png");
				_pBlockLayer->addChild(pBlock);
			}
		}

	private:
		LayerColor *_pBlockLayer;
	};

	class PositionComponent : public Component
	{
	public:
		PositionComponent() {}
		virtual ~PositionComponent()
		{
			_x = 0.0f;
			_y = 0.0f;
		}

	public:
		float _x;
		float _y;
	};

	class SpeedComponent : public Component
	{
	public:
		SpeedComponent();
		virtual ~SpeedComponent();

	public:
		int _speed;
	};

	class EntityTypeComponent : public Component
	{
	public:
		EntityTypeComponent() {}
		virtual ~EntityTypeComponent() {}

	public:
		static const unsigned int RECT_ANGLE = (1 << 1);
		static const unsigned int SQUARE = (1 << 2);
		static const unsigned int L_SHAPE = (1 << 3);
		static const unsigned int SOIL_SHAPE = (1 << 4);
		static const unsigned int Z_SHAPE = (1 << 5);

	private:
		int _type;
	};

	class ShapeComponent : public Component
	{
	public:
		ShapeComponent() {}

		virtual ~ShapeComponent() {}

	public:


	};
}

#endif
