#include "pch.h"
#include "Character.h"

Character::Character(const b2WorldId& InWorldId, const b2Vec2& InLocation, const float& InSize)
{
	{
		mVelocity = b2Vec2({0.0f, 0.0f});
		mMoveSpeed = 2.0f;
	}

	{
		mBodyDef = b2DefaultBodyDef();
		mBodyDef.type = b2_dynamicBody;
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
		mRectangle.setOutlineColor(sf::Color::Green);
		mRectangle.setOutlineThickness(-1.0f);
	}
}

void Character::SetLocation(const float& InX, const float& InY)
{
    mRectangle.setPosition({ InX, InY });
}

void Character::AddMovementInput(b2Vec2 WorldDirection, float InScaleValue)
{
	mVelocity = WorldDirection * InScaleValue;
}

void Character::MoveForward(float InScaleValue)
{
	if (InScaleValue != 0.0f)
	{
		AddMovementInput(b2Vec2({ 0.0f, 1.0f }), InScaleValue);
	}
}

void Character::MoveRight(float InScaleValue)
{
	if (InScaleValue != 0.0f)
	{
		AddMovementInput(b2Vec2({ 1.0f, 0.0f }), InScaleValue);
	}
}

void Character::Event()
{
	mVelocity = { 0.0f, 0.0f };

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::W))	MoveForward(-1.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::S))	MoveForward(+1.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::A))	MoveRight(-1.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::D))	MoveRight(+1.0f);

	b2Body_SetLinearVelocity(mBodyId, mVelocity * mMoveSpeed);
}

void Character::Tick()
{
	
}

void Character::Render(sf::RenderWindow* InWindow)
{
	b2Vec2 position = b2Body_GetPosition(mBodyId);
	b2Rot rotation = b2Body_GetRotation(mBodyId);

	SetLocation(position.x * SCALE, position.y * SCALE);

	InWindow->draw(mRectangle);
}