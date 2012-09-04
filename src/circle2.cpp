#include "circle2.h"

#include <sstream>
#include <cmath>

#include "vector2.h"
#include "line2.h"

Circle2::Circle2(void)
{
    m_center = new Vector2;
    m_radius = 0;
}

Circle2::Circle2(const Vector2& center, float radius)
{
    m_center = new Vector2(center);

    if (radius >= 0)
    {
        m_radius = radius;
    }
    else
    {
        m_radius = 0;
    }
}

Circle2::Circle2(const Circle2& other)
{
    m_center = new Vector2(*other.center());
    m_radius = other.radius();
}

Circle2::~Circle2(void)
{
    delete m_center;
    m_center = 0;
}

float Circle2::circumference(void) const
{
    float circumference = 2 * M_PI * m_radius;

    return circumference;
}

float Circle2::area(void) const
{
    float area = M_PI * pow(m_radius, 2);

    return area;
}

const Vector2* Circle2::center(void) const
{
    return m_center;
}

float Circle2::radius(void) const
{
    return m_radius;
}

bool Circle2::contains(const Vector2& point) const
{
    bool contains = m_center->distanceFrom(point) <= m_radius;

    return contains;
}

bool Circle2::contains(const Line2& line) const
{
    bool contains = (m_center->distanceFrom(*line.startPoint()) <= m_radius) && (m_center->distanceFrom(*line.endPoint()) <= m_radius);

    return contains;
}

void Circle2::scale(float factor)
{
    if (factor >= 0)
    {
        m_radius = m_radius * factor;
    }
}

std::string Circle2::toString(void) const
{
    std::string rStr;
    std::ostringstream outStringStream;

    outStringStream << m_radius;
    rStr = outStringStream.str();

    std::string circle2Info = "(" + m_center->toString() + " - " + rStr + ")";

    return circle2Info;
}

std::ostream& operator << (std::ostream& out, const Circle2& circle2)
{
    out << circle2.toString();

    return out;
}
