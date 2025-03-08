#include "pch.h"
#include "Wall.h"

Wall::Wall(const b2WorldId& InWorldId, const b2Vec2& InLocation, const float& InSize)
{
	{
		mBodyDef = b2DefaultBodyDef();
		mBodyDef.type = b2_staticBody;
		mBodyDef.position = b2Vec2({ (InLocation.x) / SCALE, InLocation.y / SCALE });

		mBodyId = b2CreateBody(InWorldId, &mBodyDef);
	}

	{
		mDynamicBox = b2MakeBox(InSize / SCALE_SIZE, InSize / SCALE_SIZE);

		mShapeDef = b2DefaultShapeDef();
		mShapeDef.density = 1.0f;
		mShapeDef.friction = 0.0f;

		b2CreatePolygonShape(mBodyId, &mShapeDef, &mDynamicBox);
	}

	{
		mRectangle.setSize({ InSize, InSize });
		mRectangle.setOrigin({ InSize / 2.0f, InSize / 2.0f });
		mRectangle.setFillColor(sf::Color::Black);
		mRectangle.setOutlineColor(sf::Color::Red);
		mRectangle.setOutlineThickness(-1.0f);
	}
}

void Wall::SetLocation(const float& InX, const float& InY)
{
	mRectangle.setPosition({ InX, InY });
}

void Wall::Event()
{
}

void Wall::Tick()
{
}

void Wall::Render(sf::RenderWindow* InWindow)
{
	b2Vec2 position = b2Body_GetPosition(mBodyId);
	b2Rot rotation = b2Body_GetRotation(mBodyId);

	SetLocation(position.x * SCALE, position.y * SCALE);

	InWindow->draw(mRectangle);
}
