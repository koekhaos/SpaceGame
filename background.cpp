#include <background.hpp>
#include <StringHelpers.hpp>

std::default_random_engine random;

Stars::Stars()
: density(0)
, speed(0)
, image()
, texture()
, position()
, starsVec()
{

}

void Stars::init(int distribution)
{
    if (!image.loadFromFile("BgStars.bmp"))
	{
		// Handle loading error
	}

    std::discrete_distribution<int> starTypeDis;
    std::uniform_int_distribution<int> starPosXDis;
    std::uniform_int_distribution<int> starPosYDis;

	image.createMaskFromColor(sf::Color::Magenta, 0);
    texture.loadFromImage(image);

    if(distribution == 1)
        starTypeDis = std::discrete_distribution<int>{10,1,0.5,0.25,0.001,0.0005};
    else if(distribution == 2)
        starTypeDis = std::discrete_distribution<int>{5,1.5,1,0.25,0.01,0.005};
    else if(distribution == 3)
        starTypeDis = std::discrete_distribution<int>{1,2,1,0.5,0.1,0.05};

    starPosXDis = std::uniform_int_distribution<int>(-50,SCREEN_WIDTH+50);
    starPosYDis = std::uniform_int_distribution<int>(-50,SCREEN_HEIGHT+50);

    for(size_t i=0;i<density;i++)
    {
        sf::IntRect starType(starTypeDis(random)*10,0,10,10);
        sf::Vector2f starPosition(starPosXDis(random),starPosYDis(random));

        sf::Sprite tempSprite;
        tempSprite.setTexture(texture);
        tempSprite.setTextureRect(starType);
        tempSprite.setPosition(starPosition);
        tempSprite.setColor(getColor());
        starsVec.push_back(tempSprite);
    }
}

void Stars::update(sf::Vector2f tMovement)
{
    sf::Vector2f movement;

    movement.x = tMovement.x - position.x;
    movement.y = tMovement.y - position.y;
    position = tMovement;

    for(size_t i=0;i<starsVec.size();i++)
    {
        sf::Vector2f starPosition = starsVec[i].getPosition();
        sf::Vector2f starMovement;

        if(starPosition.x > SCREEN_WIDTH+50)
            starMovement.x = (-SCREEN_WIDTH-100) + (-movement.x * speed);
        else if(starPosition.x < -50)
            starMovement.x = (SCREEN_WIDTH+100) + (-movement.x * speed);
        else
            starMovement.x = -movement.x * speed;

        if(starPosition.y > SCREEN_HEIGHT+50)
            starMovement.y = (-SCREEN_HEIGHT-100) + (-movement.y * speed);
        else if(starPosition.y < -50)
            starMovement.y = (SCREEN_HEIGHT+100) + (-movement.y * speed);
        else
            starMovement.y = -movement.y * speed;

        starsVec[i].move(starMovement);
    }
}

void Stars::render(sf::RenderWindow *temp)
{
    for(size_t i=0;i<starsVec.size();i++)
    {
        temp->draw(starsVec[i]);
    }
}

void Stars::setDensity(int tempDensity)
{
    density = tempDensity;
}

void Stars::setSpeed(float tempSpeed)
{
    speed = tempSpeed;
}

sf::Color Stars::getColor()
{
    static std::uniform_int_distribution<int> starColor;
    starColor = std::uniform_int_distribution<int>(1,7);

    int red = 0;
    int green = 0;
    int blue = 0;
    int alpha = 255;
    sf::Color color = sf::Color(0,0,0);

    switch(starColor(random))
    {
    case 1:
        return color = sf::Color(155,176,255,alpha);
        break;
    case 2:
        return color = sf::Color(170,191,255,alpha);
        break;
    case 3:
        return color = sf::Color(202,216,255,alpha);
        break;
    case 4:
        return color = sf::Color(248,247,255,alpha);
        break;
    case 5:
        return color = sf::Color(254,244,234,alpha);
        break;
    case 6:
        return color = sf::Color(254,210,163,alpha);
        break;
    case 7:
        return color = sf::Color(255,204,115,alpha);
        break;
    }
}
