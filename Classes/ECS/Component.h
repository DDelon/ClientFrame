#ifndef __COMPONENT_H__
#define __COMPONENT_H__

#include "cocos2d.h"
USING_NS_CC;

#define RENDER_COMPONENT		(1 << 1)
#define SPRITERENDER_COMPONENT	(1 << 2)
#define POSITION_COMPONENT		(1 << 3)
#define SPEED_COMPONENT			(1 << 4)
#define TIME_COMPONENT			(1 << 5)
#define DIRECTION_COMPONENT		(1 << 6)
#define STATUS_COMPONENT		(1 << 7)
#define ENTITY_TYPE_COMPONENT	(1 << 8)

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
		RenderComponent() {}
		~RenderComponent() 
		{

			_pBlockLayer->removeFromParent();
		}
	public:
		LayerColor *_pBlockLayer;
	};

	class SpriteRenderComponent : public Component
	{
	public:
		SpriteRenderComponent() {}
		~SpriteRenderComponent() 
		{
			_pSprite->removeFromParent();
		}

	public:
		Sprite *_pSprite;
	};

	class PositionComponent : public Component
	{
	public:
		PositionComponent() {}
		~PositionComponent() {}

	public:
		float _x;
		float _y;
	};

	class SpeedComponent : public Component
	{
	public:
		SpeedComponent() {}
		~SpeedComponent() {}

	public:
		float _speedX;
		float _speedY;
	};

	class TimeComponent : public Component
	{
	public:
		TimeComponent(float time) : _timeConst(time), _isArrival(true) {}
		~TimeComponent() {}

	public:
		const float _timeConst;
		bool _isArrival;

	};

	class DirectionComponent : public Component
	{
	public:
		DirectionComponent() {}
		~DirectionComponent() {}

	public:
		static const unsigned int NONE = 0;
		static const unsigned int LEFT = (1 << 1);
		static const unsigned int RIGHT = (1 << 2);
		static const unsigned int UP = (1 << 3);
		static const unsigned int DOWN = (1 << 4);

	public:
		int _direction;
	};

	class StatusComponent : public Component
	{
	public:
		StatusComponent() {}
		~StatusComponent() {}

	public:
		static const unsigned int FALL = (1 << 1);
		static const unsigned int STOP = (1 << 2);

	public:
		int _status;
	};

	class EntityTypeComponent : public Component
	{
	public:
		EntityTypeComponent() {}
		~EntityTypeComponent() {}

	public:
		static const unsigned int RECT_ANGLE = (1 << 1);
		static const unsigned int SQUARE = (1 << 2);
		static const unsigned int L_SHAPE = (1 << 3);
		static const unsigned int SOIL_SHAPE = (1 << 4);
		static const unsigned int Z_SHAPE = (1 << 5);

	public:
		int _type;
	};
}

#endif
