#include <Ship.hpp>

//Ship::Ship(std::string tTexture)
//{
//    if (!texture.loadFromFile(tTexture))
//	{
//		// Handle loading error
//	}
//	//texture.setSmooth(true);
//
//    sprite.setTexture(texture);
//    sprite.setOrigin(sprite.getLocalBounds().width/2,sprite.getLocalBounds().height/2);
//    sprite.setRotation(FixDegree(angle - 90.0f));
//}

void Ship::setVelocity(float tVelocity)
{
    velocity = tVelocity;
}

void Ship::changeVelocity(float tVelocity)
{
    velocity += tVelocity;
    if(velocity > maxSpeed)
        velocity = maxSpeed;
    if(velocity < 0)
        velocity = 0;
}

float Ship::getVelocity()
{
    return velocity;
}

void Ship::setMaxSpeed(float tMaxSpeed)
{
    maxSpeed = tMaxSpeed;
}

float Ship::getMaxSpeed()
{
    return maxSpeed;
}

void Ship::setAgility(float tAgility)
{
    agility = tAgility;
}

float Ship::getAgility()
{
    return agility;
}

void Ship::setThrust(float tThrust)
{
    thrust = tThrust;
}

float Ship::getThrust()
{
    return thrust;
}

void Ship::setTarget(Entity *tTarget)
{
    target = tTarget;
}

Entity Ship::getTarget()
{
    return *target;
}

void Ship::setFireRate(sf::Time tFireRate)
{
    fireRate = tFireRate;
}

float Ship::fire(Entity *tEnt, Projectiles *tProj, sf::Time elapsedTime)
{
    if (firingTimer >= fireRate)
    {
        tProj->add("laser_sm.png", tEnt->getPosition(), 1000.0f + this->getVelocity(), tEnt->getAngle(), sf::seconds(5.0f), sf::Color(0,0,255));

        firingTimer = sf::seconds(0.0f);
    }
}

void Ship::update(sf::Time elapsedTime)
{
    sf::Vector2f movement;
    sf::Vector2f origin = offset;

    if(parent != nullptr)
    {
        movement = parent->getPosition();
        origin.x -= parent->getOrigin().x;
        origin.y -= parent->getOrigin().y;
        float tAngle = FixDegree(ConvertRadianToDegree(AngleToTarget(sf::Vector2f(0,0),origin)));
        float tLength = LengthToTarget(sf::Vector2f(0,0),origin);

        movement.x -= tLength * cos(ConvertDegreeToRadian(FixDegree(tAngle+parent->getAngle()-90)));
        movement.y -= tLength * sin(ConvertDegreeToRadian(FixDegree(tAngle+parent->getAngle()-90)));

        sprite.setPosition(movement);

//        if(AI==true)
//        {
//            float targetAngle = FixDegree(ConvertRadianToDegree(AngleToTarget(sprite.getPosition(),target->getPosition())) + 180);
//
//            if(FixDegree(sprite.getRotation() - targetAngle) <= 180.0f)
//                rotate(-agility);
//            if(FixDegree(sprite.getRotation() - targetAngle) > 180.0f)
//                rotate(agility);
//        }

        sprite.setRotation(FixDegree(parent->getAngle() + angle - 90.0f));
    }
    else
    {
        movement.x = cos(ConvertDegreeToRadian(sprite.getRotation())) * (velocity * elapsedTime.asSeconds());
        movement.y = sin(ConvertDegreeToRadian(sprite.getRotation())) * (velocity * elapsedTime.asSeconds());

        sprite.setRotation(FixDegree(angle - 90.0f));
        sprite.move(movement);
    }

    if(bottomChildren.size() > 0)
    {
        for(int i=0;i < bottomChildren.size();i++)
        {
            bottomChildren[i]->update(elapsedTime);
        }
    }

    if(topChildren.size() > 0)
    {
        for(int i=0;i < topChildren.size();i++)
        {
            topChildren[i]->update(elapsedTime);
        }
    }

    firingTimer += elapsedTime;
}
