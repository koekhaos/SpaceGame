#include <Globals.hpp>

double ConvertDegreeToRadian(double degree)
{
    double radian;
    radian = degree * PI / 180;
    return radian;
}

double ConvertRadianToDegree(double radian)
{
    double degree;
    degree =  radian * 180 / PI;
    return degree;
}

double AngleToTarget(double x1, double y1, double x2, double y2)
{
	double deltaX = (x2 - x1);
	double deltaY = (y2 - y1);

    return atan2(deltaY, deltaX);
}

float AngleToTarget(sf::Vector2f a, sf::Vector2f b)
{
    float deltaX = a.x - b.x;
    float deltaY = a.y - b.y;

    return atan2(deltaY, deltaX);
}

float LengthToTarget(sf::Vector2f a, sf::Vector2f b)
{
    float deltaX = a.x - b.x;
    float deltaY = a.y - b.y;

    return sqrt(deltaX*deltaX + deltaY*deltaY);
}

float AngleDifference(float angle, float target)
{
    return FixDegree(angle - target);
}

float FixDegree(float tDegree)
{
    while(tDegree >= 360.0f)
        tDegree -= 360.0f;
    while(tDegree < 0.0f)
        tDegree += 360.0f;

    return tDegree;
}
