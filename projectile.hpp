#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#include <SFML/Graphics.hpp>
#include <Globals.hpp>
#include <vector>
#include <Entity.hpp>

class Projectile
{
	public:
        Projectile();
        Projectile(std::string tTexture, sf::Vector2f tPosition, float tVelocity, float tAngle, sf::Time tTimeToLiveLimit, sf::Color tColor);
        void setTarget(Entity *tTarget);
        Projectile getTarget();
        void setParent(Entity *tParent);
        sf::Time getTimeToLiveLimit();
        sf::Time getTimeToLive();

        void update(sf::Time elapsedTime);
        void draw(sf::RenderWindow *tWindow);

	private:
        sf::Texture texture;
        sf::Sprite sprite;
        float velocity;
        float angle;
        sf::Time timeToLive;
        sf::Time timeToLiveLimit;
        sf::Color color;

        Entity *target;
        Entity *parent;
};

#endif // PROJECTILE_HPP
