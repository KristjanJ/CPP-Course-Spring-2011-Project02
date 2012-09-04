#include "sphere3.h"

#include <sstream>
#include <cmath>

#include "vector3.h"
#include "line3.h"

Sphere3::Sphere3(void)
{
    m_center = new Vector3;
    m_radius = 0;
}

Sphere3::Sphere3(const Vector3& center, float radius)
{
    m_center = new Vector3(center);

	if (radius >= 0)
    {
        m_radius = radius;
    }
    else
    {
        m_radius = 0;
    }
}

Sphere3::Sphere3(const Sphere3& other)
{
    m_center = new Vector3(*other.center());
    m_radius = other.radius();
}

Sphere3::~Sphere3(void)
{
    delete m_center;
    m_center = 0;
}

float Sphere3::circumference(void) const
{
    float circumference = 2 * M_PI * m_radius;

    return circumference;
}

float Sphere3::area(void) const
{
    float area = 4 * M_PI * pow(m_radius, 2);

    return area;
}

float Sphere3::volume(void) const
{
    float volume = (4 / 3) * M_PI * pow(m_radius, 3);

    return volume;
}

const Vector3* Sphere3::center(void) const
{
    return m_center;
}

float Sphere3::radius(void) const
{
    return m_radius;
}

bool Sphere3::contains(const Vector3& point) const
{
    bool contains = m_center->distanceFrom(point) <= m_radius;

    return contains;
}

bool Sphere3::contains(const Line3& line) const
{
    bool contains = (m_center->distanceFrom(*line.startPoint()) <= m_radius) && (m_center->distanceFrom(*line.endPoint()) <= m_radius);

    return contains;
}

void Sphere3::scale(float factor)
{
	if (factor >= 0)
    {
        m_radius = m_radius * factor;
    }
}

std::string Sphere3::toString(void) const
{
    std::string rStr;
    std::ostringstream outStringStream;

    outStringStream << m_radius;
    rStr = outStringStream.str();

    std::string Sphere3Info = "(" + m_center->toString() + " - " + rStr + ")";

    return Sphere3Info;
}

std::ostream& operator << (std::ostream& out, const Sphere3& Sphere3)
{
    out << Sphere3.toString();

    return out;
}
