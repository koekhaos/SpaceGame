#include <Entity.hpp>

Entity::Entity(std::string tTexture)
: texture()
, sprite()
, angle(0)
, maxAngle(0)
, minAngle(0)
, offsetAngle(0)
, offset(sf::Vector2f(0,0))
, parent(nullptr)
, bottomChildren()
, topChildren()
{
    if (!texture.loadFromFile(tTexture))
	{
		// Handle loading error
	}
	texture.setSmooth(true);

    sprite.setTexture(texture);
    sprite.setOrigin(sprite.getLocalBounds().width/2,sprite.getLocalBounds().height/2);
    sprite.setRotation(FixDegree(angle - 90.0f));
    sprite.setPosition(0.0f,0.0f);
}

void Entity::rotate(float tAngle)
{
    angle = FixDegree(angle + tAngle);

    if(minAngle != 0 && maxAngle != 0)
    {
        float dAngle = ((minAngle - maxAngle) / 2) + maxAngle;

        if(maxAngle < minAngle)
        {
            if(angle > maxAngle && angle < dAngle)
                angle = maxAngle;
            if(angle < minAngle && angle > dAngle)
                angle = minAngle;
        }
        else
        {
            if(angle > maxAngle)
                angle = maxAngle;
            if(angle < minAngle)
                angle = minAngle;
        }
    }
}

void Entity::setAngle(float tAngle)
{
    angle = tAngle;
}

float Entity::getAngle()
{
    return angle;
}

void Entity::setMaxAngle(float tAngle)
{
    maxAngle = tAngle;
}

float Entity::getMaxAngle()
{
    return maxAngle;
}

void Entity::setMinAngle(float tAngle)
{
    minAngle = tAngle;
}

float Entity::getMinAngle()
{
    return minAngle;
}

void Entity::setOffsetAngle(float tAngle)
{
    offsetAngle = tAngle;
}

float Entity::getOffsetAngle()
{
    return offsetAngle;
}

void Entity::setOffset(sf::Vector2f tOffset)
{
    offset = tOffset;
}

void Entity::setPosition(sf::Vector2f tPosition)
{
    sprite.setPosition(tPosition);
}

sf::Vector2f Entity::getPosition()
{
    return sprite.getPosition();
}

sf::Vector2f Entity::getOrigin()
{
    return sprite.getOrigin();
}

void Entity::setParent(Entity *tParent)
{
    parent = tParent;
}

void Entity::addTopChild(Entity *tChild)
{
    bottomChildren.push_back(tChild);
}

void Entity::addBottomChild(Entity *tChild)
{
   topChildren.push_back(tChild);
}

float Entity::getRotation()
{
    return sprite.getRotation();
}

float Entity::fire()
{
    //
}

void Entity::update(sf::Time elapsedTime)
{
//    sf::Vector2f movement;
//    sf::Vector2f origin = offset;
//
//    if(parent != nullptr)
//    {
//        movement = parent->getPosition();
//        origin.x -= parent->getOrigin().x;
//        origin.y -= parent->getOrigin().y;
//        float tAngle = FixDegree(ConvertRadianToDegree(AngleToTarget(sf::Vector2f(0,0),origin)));
//        float tLength = LengthToTarget(sf::Vector2f(0,0),origin);
//
//        movement.x -= tLength * cos(ConvertDegreeToRadian(FixDegree(tAngle+parent->getAngle()-90)));
//        movement.y -= tLength * sin(ConvertDegreeToRadian(FixDegree(tAngle+parent->getAngle()-90)));
//
//        sprite.setPosition(movement);
//
//        if(AI==true)
//        {
//            float targetAngle = FixDegree(ConvertRadianToDegree(AngleToTarget(sprite.getPosition(),target->getPosition())) + 180);
//
//            if(FixDegree(sprite.getRotation() - targetAngle) <= 180.0f)
//                rotate(-agility);
//            if(FixDegree(sprite.getRotation() - targetAngle) > 180.0f)
//                rotate(agility);
//        }
//
//        sprite.setRotation(FixDegree(parent->getAngle() + angle - 90.0f));
//    }
//    else
//    {
//        movement.x = cos(ConvertDegreeToRadian(sprite.getRotation())) * (velocity * elapsedTime.asSeconds());
//        movement.y = sin(ConvertDegreeToRadian(sprite.getRotation())) * (velocity * elapsedTime.asSeconds());
//
//        sprite.setRotation(FixDegree(angle - 90.0f));
//        sprite.move(movement);
//    }
//
//    if(bottomChildren.size() > 0)
//    {
//        for(int i=0;i < bottomChildren.size();i++)
//        {
//            bottomChildren[i]->update(elapsedTime);
//        }
//    }
//
//    if(topChildren.size() > 0)
//    {
//        for(int i=0;i < topChildren.size();i++)
//        {
//            topChildren[i]->update(elapsedTime);
//        }
//    }
}

void Entity::draw(sf::RenderWindow *tWindow)
{
    if(topChildren.size() > 0)
    {
        for(int i=0;i < topChildren.size();i++)
        {
            topChildren[i]->draw(tWindow);
        }
    }

    tWindow->draw(sprite);

    if(bottomChildren.size() > 0)
    {
        for(int i=0;i < bottomChildren.size();i++)
        {
            bottomChildren[i]->draw(tWindow);
        }
    }
}
