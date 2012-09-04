#include "vector3.h"

#include <iostream>
#include <sstream>
#include <cmath>

Vector3::Vector3(void)
{
	x = 0;
	y = 0;
	z = 0;
}

Vector3::Vector3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3::Vector3(const Vector3& other)
{
    x = other.x;
    y = other.y;
    z = other.z;
}

Vector3::~Vector3(void)
{

}

float Vector3::distanceFrom(const Vector3& other) const
{
    float fNum = pow((x - other.x), 2) + pow((y - other.y), 2) + pow((z - other.z), 2);

    float distance = sqrt(fNum);

    return distance;
}

std::string Vector3:: toString(void) const
{
    std::string vector3Info;
    std::string xStr;
    std::string yStr;
    std::string zStr;

    std::ostringstream outStringStream;
    outStringStream << x;
    xStr = outStringStream.str();
    outStringStream.str("");
    outStringStream << y;
    yStr = outStringStream.str();
    outStringStream.str("");
    outStringStream << z;
    zStr = outStringStream.str();

    vector3Info = "(" + xStr + ", " + yStr + ", " + zStr + ")";

    return vector3Info;
}

std::ostream& operator << (std::ostream& out, const Vector3& vector3)
{
    out << vector3.toString();

    return out;
}
