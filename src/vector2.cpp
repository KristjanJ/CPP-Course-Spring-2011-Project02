#include "vector2.h"

#include <iostream>
#include <sstream>
#include <cmath>

Vector2::Vector2(void)
{
	x = 0;
	y = 0;
}

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2::Vector2(const Vector2& other)
{
    x = other.x;
    y = other.y;
}

Vector2::~Vector2(void)
{

}

float Vector2::distanceFrom(const Vector2& other) const
{
    float fNum = pow((x - other.x), 2) + pow((y - other.y), 2);

    float distance = sqrt(fNum);

    return distance;
}

std::string Vector2:: toString(void) const
{
    std::string vector2Info;
    std::string xStr;
    std::string yStr;

    std::ostringstream outStringStream;
    outStringStream << x;
    xStr = outStringStream.str();
    outStringStream.str("");
    outStringStream << y;
    yStr = outStringStream.str();

    vector2Info = "(" + xStr + ", " + yStr + ")";

    return vector2Info;
}

std::ostream& operator << (std::ostream& out, const Vector2& vector2)
{
    out << vector2.toString();

    return out;
}
