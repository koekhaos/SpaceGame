#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics.hpp>
#include <Globals.hpp>
#include <vector>
#include <string>

class Entity
{
	public:
        //Entity() = default;
        Entity(std::string tTexture);

        void rotate(float tAngle);
        void setAngle(float tAngle);
        float getAngle();
        void setMaxAngle(float tAngle);
        float getMaxAngle();
        void setMinAngle(float tAngle);
        float getMinAngle();
        void setOffsetAngle(float tAngle);
        float getOffsetAngle();
        void setPosition(sf::Vector2f tPosition);
        sf::Vector2f getPosition();
        void setOffset(sf::Vector2f tOffset);
        sf::Vector2f getOrigin();
        void setAI(bool tAI);
        void setProjectile(bool tProjectile);
        void setMaxDistance(float tDistance);
        float getMaxDistance();
        float getRotation();

        virtual float fire();

        void setParent(Entity *tParent);
        void addBottomChild(Entity *tChild);
        void addTopChild(Entity *tChild);

        virtual void update(sf::Time elapsedTime);
        void draw(sf::RenderWindow *tWindow);


	protected:
        sf::Texture texture;
        sf::Sprite sprite;

        float angle = 0.0f;
        float maxAngle = 0.0f;
        float minAngle = 0.0f;
        float offsetAngle = 0.0f;
        sf::Vector2f offset = sf::Vector2f(0.0f,0.0f);

        Entity *parent;
        std::vector<Entity*> bottomChildren;
        std::vector<Entity*> topChildren;
};

#endif // ENTITY_HPP
