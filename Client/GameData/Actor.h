#pragma once

class Actor
{
public:
	Actor();

public:
	virtual void Event() {}
	virtual void Tick() {}
	virtual void Render(sf::RenderWindow* InWindow) {}

};

