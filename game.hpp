#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <Globals.hpp>
#include <background.hpp>
#include <Entity.hpp>
#include <Ship.hpp>
#include <projectile.hpp>
#include <Projectiles.hpp>

class Game : private sf::NonCopyable
{
public:
    Game();
    void run();

    sf::RenderWindow gameWindow;

private:
    void processEvents();
    void update(sf::Time elapsedTime);
    void render();
    void updateStatistics(sf::Time elapsedTime);
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

private:
    static const sf::Time TimePerFrame;

    sf::View gameView;
    sf::Font gameFont;
    sf::Text statisticsText;
    sf::Time statisticsUpdateTime;

    Ship ship;
    Ship ship2;
    Ship turret;
    Ship station;
    Ship station_turret1;
    Ship station_turret2;
    Ship station_turret3;
    Ship station_turret4;

    Ship station2;
    Ship station2_turret1;
    Ship station2_turret2;
    Ship station2_turret3;
    Ship station2_turret4;

    Projectiles projectiles;

    Stars BGStars;
    Stars MGStars;
    Stars FGStars;

    std::size_t statisticsNumFrames;

    bool isMovingUp;
    bool isMovingDown;
    bool isMovingRight;
    bool isMovingLeft;
    bool isZoomingIn;
    bool isZoomingOut;
    bool isTurretLeft;
    bool isTurretRight;
    bool isFiring;
};

#endif // GAME_HPP
