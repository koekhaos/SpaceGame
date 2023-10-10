#include <StringHelpers.hpp>
#include <game.hpp>

const sf::Time Game::TimePerFrame = sf::seconds(1.f/60.f);

Game::Game()
: gameWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML Test 1", sf::Style::Close)
, gameView(gameWindow.getDefaultView())
, gameFont()
, statisticsText()
, statisticsUpdateTime()
, ship("spaceship.png")
, ship2("spaceship.png")
, turret("turret.png")
, station("station.png")
, station_turret1("station_turret.png")
, station_turret2("station_turret.png")
, station_turret3("station_turret.png")
, station_turret4("station_turret.png")
, station2("station.png")
, station2_turret1("station_turret.png")
, station2_turret2("station_turret.png")
, station2_turret3("station_turret.png")
, station2_turret4("station_turret.png")
, projectiles()
, BGStars()
, MGStars()
, FGStars()
, statisticsNumFrames(0)
, isMovingUp(false)
, isMovingDown(false)
, isMovingRight(false)
, isMovingLeft(false)
, isZoomingIn(false)
, isZoomingOut(false)
, isTurretLeft(false)
, isTurretRight(false)
, isFiring(false)
{
	gameView.setCenter(ship.getPosition().x,ship.getPosition().y);

	ship.setMaxSpeed(1000.0f);
	ship.setThrust(10.0f);
	ship.setAgility(2.0f);
	ship.setAngle(0.0f);
	ship.setOffsetAngle(270.0f);
	ship.setFireRate(sf::seconds(0.3f));
	ship.addTopChild(&turret);

	turret.setParent(&ship);
	turret.setOffset(sf::Vector2f(21,100));
	turret.setAgility(2.0f);
	turret.setAngle(180.0f);
	turret.setOffsetAngle(180.0f);
	turret.setMaxAngle(220.0f);
	turret.setMinAngle(140.0f);
	//turret.setAI(true);
	turret.setTarget(&station_turret1);

	ship2.setPosition(sf::Vector2f(200,200));

	station.setPosition(sf::Vector2f(200,200));
	station.addTopChild(&station_turret1);
	station.addTopChild(&station_turret2);
	station.addTopChild(&station_turret3);
	station.addTopChild(&station_turret4);

	station_turret1.setParent(&station);
	station_turret1.setOffset(sf::Vector2f(110,90));
	station_turret1.setAngle(225.0f);
	station_turret1.setOffsetAngle(225.0f);
	station_turret1.setAgility(0.5f);
	station_turret1.setMaxAngle(300.0f);
	station_turret1.setMinAngle(150.0f);
	//station_turret1.setAI(true);
	station_turret1.setTarget(&ship);

	station_turret2.setParent(&station);
	station_turret2.setOffset(sf::Vector2f(815,95));
	station_turret2.setAngle(315.0f);
	station_turret2.setOffsetAngle(315.0f);
	station_turret2.setAgility(0.5f);
	station_turret2.setMaxAngle(30.0f);
	station_turret2.setMinAngle(240.0f);
	//station_turret2.setAI(true);
	station_turret2.setTarget(&ship);

	station_turret3.setParent(&station);
	station_turret3.setOffset(sf::Vector2f(94,801));
	station_turret3.setAngle(135.0f);
	station_turret3.setOffsetAngle(135.0f);
	station_turret3.setAgility(0.5f);
	station_turret3.setMaxAngle(210.0f);
	station_turret3.setMinAngle(60.0f);
	//station_turret3.setAI(true);
	station_turret3.setTarget(&ship);

	station_turret4.setParent(&station);
	station_turret4.setOffset(sf::Vector2f(770,828));
	station_turret4.setAngle(45.0f);
	station_turret4.setOffsetAngle(45.0f);
	station_turret4.setAgility(0.5f);
	station_turret4.setMaxAngle(120.0f);
	station_turret4.setMinAngle(330.0f);
	//station_turret4.setAI(true);
	station_turret4.setTarget(&ship);

	station2.setPosition(sf::Vector2f(1200,200));
	station2.addTopChild(&station2_turret1);
	station2.addTopChild(&station2_turret2);
	station2.addTopChild(&station2_turret3);
	station2.addTopChild(&station2_turret4);

	station2_turret1.setParent(&station2);
	station2_turret1.setOffset(sf::Vector2f(110,90));
	station2_turret1.setAngle(225.0f);
	station2_turret1.setOffsetAngle(225.0f);
	station2_turret1.setAgility(0.5f);
	station2_turret1.setMaxAngle(300.0f);
	station2_turret1.setMinAngle(150.0f);
	//station2_turret1.setAI(true);
	station2_turret1.setTarget(&ship);

	station2_turret2.setParent(&station2);
	station2_turret2.setOffset(sf::Vector2f(815,95));
	station2_turret2.setAngle(315.0f);
	station2_turret2.setOffsetAngle(315.0f);
	station2_turret2.setAgility(0.5f);
	station2_turret2.setMaxAngle(30.0f);
	station2_turret2.setMinAngle(240.0f);
	//station2_turret2.setAI(true);
	station2_turret2.setTarget(&ship);

	station2_turret3.setParent(&station2);
	station2_turret3.setOffset(sf::Vector2f(94,801));
	station2_turret3.setAngle(135.0f);
	station2_turret3.setOffsetAngle(135.0f);
	station2_turret3.setAgility(0.5f);
	station2_turret3.setMaxAngle(210.0f);
	station2_turret3.setMinAngle(60.0f);
	//station2_turret3.setAI(true);
	station2_turret3.setTarget(&ship);

	station2_turret4.setParent(&station2);
	station2_turret4.setOffset(sf::Vector2f(770,828));
	station2_turret4.setAngle(45.0f);
	station2_turret4.setOffsetAngle(45.0f);
	station2_turret4.setAgility(0.5f);
	station2_turret4.setMaxAngle(120.0f);
	station2_turret4.setMinAngle(330.0f);
	//station2_turret4.setAI(true);
	station2_turret4.setTarget(&ship);

	if(!gameFont.loadFromFile("arial.ttf"))
    {
        //fail errors at some point.
    }
	statisticsText.setFont(gameFont);
	statisticsText.setPosition(5.0f, 5.0f);
	statisticsText.setCharacterSize(10);

    BGStars.setDensity(500);
    BGStars.setSpeed(0.01f);
    BGStars.init(1);

    MGStars.setDensity(100);
    MGStars.setSpeed(0.02f);
    MGStars.init(2);

    FGStars.setDensity(20);
    FGStars.setSpeed(0.03f);
    FGStars.init(3);
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (gameWindow.isOpen())
	{
		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;

			processEvents();
			update(TimePerFrame);
		}

		updateStatistics(elapsedTime);
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (gameWindow.pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::KeyPressed:
				handlePlayerInput(event.key.code, true);
				break;

			case sf::Event::KeyReleased:
				handlePlayerInput(event.key.code, false);
				break;

			case sf::Event::Closed:
				gameWindow.close();
				break;
		}
	}
}

void Game::update(sf::Time elapsedTime)
{
	sf::Vector2f movement(0.f, 0.f);
	if (isMovingUp)
    {
		ship.changeVelocity(+ship.getThrust());
    }
	if (isMovingDown)
    {
        ship.changeVelocity(-ship.getThrust());
    }
	if (isMovingLeft)
    {
		ship.rotate(-ship.getAgility());
    }
	if (isMovingRight)
    {
        ship.rotate(+ship.getAgility());
    }
    if(isTurretLeft)
    {
        station.rotate(-turret.getAgility());
    }
    if(isTurretRight)
    {
        station.rotate(turret.getAgility());
    }

    if(isZoomingIn)
    {
        gameView.zoom(0.95f);
        if(gameView.getSize().x < SCREEN_WIDTH/2)
            gameView.setSize(SCREEN_WIDTH/2,SCREEN_HEIGHT/2);
    }
    if(isZoomingOut)
    {
        gameView.zoom(1.05f);
        if(gameView.getSize().x > SCREEN_WIDTH*5)
            gameView.setSize(SCREEN_WIDTH*5,SCREEN_HEIGHT*5);
    }

    if(isFiring)
    {
        ship.fire(&ship, &projectiles, elapsedTime);
    }

	ship.update(elapsedTime);
	ship2.update(elapsedTime);
	station.update(elapsedTime);
	station2.update(elapsedTime);

	BGStars.update(ship.getPosition());
	MGStars.update(ship.getPosition());
	FGStars.update(ship.getPosition());

	projectiles.update(elapsedTime);

	gameView.setCenter(ship.getPosition());
}

void Game::render()
{
	gameWindow.clear(sf::Color(0,0,15,0));
	BGStars.render(&gameWindow);
	MGStars.render(&gameWindow);
	FGStars.render(&gameWindow);
	gameWindow.setView(gameView);
	station.draw(&gameWindow);
	station2.draw(&gameWindow);
	ship2.draw(&gameWindow);
	ship.draw(&gameWindow);
	projectiles.draw(&gameWindow);

	gameWindow.setView(gameWindow.getDefaultView());
	gameWindow.draw(statisticsText);
	gameWindow.display();
}

void Game::updateStatistics(sf::Time elapsedTime)
{
	statisticsUpdateTime += elapsedTime;
	statisticsNumFrames += 1;
	float targetAngle1 = ConvertRadianToDegree(AngleToTarget(station_turret1.getPosition(),ship.getPosition()));
	float targetAngle2 = ConvertRadianToDegree(AngleToTarget(station_turret2.getPosition(),ship.getPosition()));
	float targetAngle3 = ConvertRadianToDegree(AngleToTarget(station_turret3.getPosition(),ship.getPosition()));
	float targetAngle4 = ConvertRadianToDegree(AngleToTarget(station_turret4.getPosition(),ship.getPosition()));
	float turretTarget = FixDegree(ConvertRadianToDegree(AngleToTarget(turret.getPosition(),station_turret1.getPosition())));

	if (statisticsUpdateTime >= sf::seconds(1.0f))
	{
		statisticsText.setString(
			"Frames / Second = " + toString(statisticsNumFrames) + "\n" +
			"Time / Update = " + toString(statisticsUpdateTime.asMicroseconds() / statisticsNumFrames) + "us\n" +
            "Ship Pos = " + toString(ship.getPosition().x) + " " + toString(ship.getPosition().y) + "\n" +
            "Station Pos = " + toString(station.getPosition().x) + " " + toString(station.getPosition().y) + "\n" +
            "Ship Speed = " + toString(ship.getVelocity()) + "\n" +
            "Ship Angle = " + toString(ship.getAngle()) + "\n\n" +
            "Turret Angle = " + toString(turret.getAngle()) + "\n" +
            "Turret Rotation = " + toString(turret.getRotation()) + "\n" +
            "Turret Target = " + toString(turretTarget) + "\n\n" +
            "Turret1 Pos = " + toString(station_turret1.getPosition().x) + " " + toString(station_turret1.getPosition().y) + "\n" +
            "Target1 Angle = " + toString(targetAngle1) + "\n" +
            "Turret1 Angle = " + toString(station_turret1.getAngle()) + "\n" +
            "IsFiring = " + toString(isFiring)
            );

		statisticsUpdateTime -= sf::seconds(1.0f);
		statisticsNumFrames = 0;
	}
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
	if(key == sf::Keyboard::Escape)
        gameWindow.close();
	if (key == sf::Keyboard::Up)
		isMovingUp = isPressed;
	else if (key == sf::Keyboard::Down)
		isMovingDown = isPressed;
	else if (key == sf::Keyboard::Left)
		isMovingLeft = isPressed;
	else if (key == sf::Keyboard::Right)
		isMovingRight = isPressed;
    else if(key == sf::Keyboard::W)
        isZoomingIn = isPressed;
    else if(key == sf::Keyboard::S)
        isZoomingOut = isPressed;
    else if(key == sf::Keyboard::A)
        isTurretLeft = isPressed;
    else if(key == sf::Keyboard::D)
        isTurretRight = isPressed;
    else if(key == sf::Keyboard::Space)
        isFiring = isPressed;

}
