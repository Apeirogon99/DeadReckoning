#include "pch.h"
#include "GameData/Character.h"
#include "GameData/Wall.h"

#include <boost/asio.hpp>

int main()
{
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode({ WINDOW_WIDTH, WINDOW_HEIGHT }), "DeadReckoning");
    window->setFramerateLimit(FRAME);

    b2Vec2 center = b2Vec2({ (WINDOW_WIDTH / 2.0f), (WINDOW_HEIGHT / 2.0f) });

    b2WorldDef worldDef = b2DefaultWorldDef();
    worldDef.gravity = b2Vec2({ 0.0f, 0.0f });
    b2WorldId worldId = b2CreateWorld(&worldDef);

    vector<Actor*> actors;

    Wall* wall = new Wall(worldId, { center.x , (center.y - 100.0f) }, 30.0f);
    actors.push_back(wall);

    Character* character = new Character(worldId, center, 10.0f);
    actors.push_back(character);

    while (window->isOpen())
    {
        while (const std::optional event = window->pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window->close();
            }

            for (Actor* actor : actors)
            {
                actor->Event();
            }
        }

        for (Actor* actor : actors)
        {
            actor->Tick();
        }

        b2World_Step(worldId, TIME_STEP, SUB_STEP_COUNT);
        
        window->clear();
        for (Actor* actor : actors)
        {
            actor->Render(window);
        }
        window->display();
    }

    for (Actor* actor : actors)
    {
        delete actor;
    }

    b2DestroyWorld(worldId);
    return 0;
}