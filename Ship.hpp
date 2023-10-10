#ifndef SHIP_HPP
#define SHIP_HPP

#include <SFML/Graphics.hpp>
#include <Globals.hpp>
#include <vector>
#include <string>
#include <Entity.hpp>
#include <Projectiles.hpp>

class Ship : public Entity
{
	public:
        Ship(std::string tTexture) : Entity(tTexture)
        {
            //
        }

        void setVelocity(float tVelocity);
        void changeVelocity(float tVelocity);
        float getVelocity();
        void setMaxSpeed(float tMaxSpeed);
        float getMaxSpeed();
        void setAgility(float tAgility);
        float getAgility();
        void setThrust(float tThrust);
        float getThrust();
        float fire(Entity *tEnt, Projectiles *tProj, sf::Time elapsedTime);
        void setFireRate(sf::Time tFireRate);

        void setTarget(Entity *tTarget);
        Entity getTarget();

        void update(sf::Time elapsedTime);

	protected:
        float velocity = 0.0f;
        float maxSpeed = 0.0f;
        float agility = 0.0f;
        float thrust = 0.0f;

        sf::Time firingTimer;
        sf::Time fireRate;

        Entity *target;
};

#endif // SHIP_HPP
