#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include <SFML/Graphics.hpp>
#include <Globals.hpp>
#include <vector>
#include <random>
#include <memory>

class Stars
{
	public:
        Stars();
        void init(int distribution);
        void update(sf::Vector2f tMovement);
        void render(sf::RenderWindow *temp);
        void setDensity(int tempDensity);
        void setSpeed(float tempSpeed);
        sf::Color getColor();

	private:
        int density;
        float speed;
        sf::Image image;
        sf::Texture texture;
        sf::Vector2f position;
        std::vector<sf::Sprite> starsVec;
};

#endif // BACKGROUND_HPP
