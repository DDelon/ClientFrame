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
		RenderComponent(int shapeType) 
		{
			_pBlockLayer = LayerColor::create(Color4B(100, 100, 100, 100));
			this->createBlock(4);
			this->arrangeShape(shapeType);
			
		}
		virtual ~RenderComponent()
		{
			for (auto iter : _renderVec)
			{
				iter->removeFromParent();
			}
			_pBlockLayer->removeFromParent();
			_renderVec.clear();
		}

		bool isAdded() 
		{
			return !(_pBlockLayer->getParent() == nullptr);
		}

		void addToParent(Node *pParent)
		{
			
		}

	private:
		void createBlock(int num)
		{
			for (int i = 0; i < num; ++i)
			{
				Sprite *pBlock = Sprite::create("block1.png");
				_renderVec.push_back(pBlock);
				_pBlockLayer->addChild(pBlock);
			}

			if (_renderVec.size() > 0)
			{
				_size = _renderVec[0]->getContentSize();
			}
		}

		void arrangeShape(int shapeType)	//ÅÅÁÐÐÎ×´
		{
			switch (shapeType)
			{
			case EntityTypeComponent::RECT_ANGLE:
				//_pBlockLayer->setContentSize(Size(_size.width*4, _size.height));
				_renderVec[0]->setPosition(Size(-(_size.width * 2 - _size.width / 2), _size.height / 2));
				for (int i = 1; i < _renderVec.size(); ++i)
				{
					Vec2 pos = Vec2(_renderVec[i - 1]->getPositionX() + _size.width, _renderVec[i - 1]->getPositionY());
					_renderVec[i]->setPosition(pos);
				}

				break;
			case EntityTypeComponent::L_SHAPE:
				break;
			case EntityTypeComponent::SQUARE:
				break;
			case EntityTypeComponent::SOIL_SHAPE:
				break;
			case EntityTypeComponent::Z_SHAPE:
				break;
			}
		}

	private:
		std::vector<Sprite *> _renderVec;
		LayerColor *_pBlockLayer;
		Size _size;
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
}

#endif
