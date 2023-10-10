#ifndef GLOBALS_HPP
#define GLOBALS_HPP

#include <SFML/Graphics.hpp>

const int SCREEN_WIDTH = 1900;
const int SCREEN_HEIGHT = 1000;
const float PI = 3.141593f;

double ConvertDegreeToRadian(double degree);
double ConvertRadianToDegree(double radian);
double AngleToTarget(double x1, double y1, double x2, double y2);
float AngleToTarget(sf::Vector2f a, sf::Vector2f b);
float LengthToTarget(sf::Vector2f a, sf::Vector2f b);
float AngleDifference(float a, float b);
float FixDegree(float tDegree);

#endif // GLOBALS_HPP
