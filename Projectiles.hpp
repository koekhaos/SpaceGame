#ifndef PROJECTILES_HPP
#define PROJECTILES_HPP

#include <SFML/Graphics.hpp>
#include <Globals.hpp>
#include <vector>
#include <projectile.hpp>

class Projectiles
{
	public:
        Projectiles();

        void update(sf::Time elapsedTime);
        void draw(sf::RenderWindow *tWindow);
        void add(std::string tTexture, sf::Vector2f tPosition, float tVelocity, float tAngle, sf::Time tTimeToLiveLimit, sf::Color tColor);
        //void remove(Projectile *tProjectile);

	private:
        std::vector<Projectile*> projectilesVec;
};

#endif // PROJECTILES_HPP
