#pragma once
#include "Actor.h"

class Wall : public Actor
{
public:
	Wall(const b2WorldId& InWorldId, const b2Vec2& InLocation, const float& InSize);

public:
	void SetLocation(const float& InX, const float& InY);

//Actor
public:
	virtual void Event() override;
	virtual void Tick() override;
	virtual void Render(sf::RenderWindow* InWindow) override;

public:
	sf::RectangleShape mRectangle;

	b2BodyId	mBodyId;
	b2BodyDef	mBodyDef;

	b2Polygon	mDynamicBox;
	b2ShapeDef	mShapeDef;
};

