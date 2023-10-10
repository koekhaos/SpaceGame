#include <projectile.hpp>

Projectile::Projectile(std::string tTexture, sf::Vector2f tPosition, float tVelocity, float tAngle, sf::Time tTimeToLiveLimit, sf::Color tColor)
: texture()
, sprite()
, velocity(0)
, angle(0)
, timeToLive(sf::seconds(0.0f))
, timeToLiveLimit(sf::seconds(0.0f))
, color(sf::Color(0,0,0))
, target(nullptr)
, parent(nullptr)
{
    if(!texture.loadFromFile(tTexture))
	{
		// Handle loading error
	}
	//texture.setSmooth(true);

    sprite.setTexture(texture);
    sprite.setOrigin(sprite.getLocalBounds().width/2,sprite.getLocalBounds().height/2);
    sprite.setRotation(FixDegree(angle - 90.0f));
    sprite.setPosition(tPosition);
    sprite.setColor(tColor);
    velocity = tVelocity;
    angle = tAngle;
    timeToLiveLimit = tTimeToLiveLimit;
}

void Projectile::setParent(Entity *tParent)
{
    parent = tParent;
}

void Projectile::update(sf::Time elapsedTime)
{
    sf::Vector2f movement;

    movement.x = cos(ConvertDegreeToRadian(sprite.getRotation())) * (velocity * elapsedTime.asSeconds());
    movement.y = sin(ConvertDegreeToRadian(sprite.getRotation())) * (velocity * elapsedTime.asSeconds());

    sprite.setRotation(FixDegree(angle - 90.0f));
    sprite.move(movement);

    timeToLive += elapsedTime;
}

void Projectile::draw(sf::RenderWindow *tWindow)
{
    tWindow->draw(sprite);
}

sf::Time Projectile::getTimeToLiveLimit()
{
    return timeToLiveLimit;
}
sf::Time Projectile::getTimeToLive()
{
    return timeToLive;
}
