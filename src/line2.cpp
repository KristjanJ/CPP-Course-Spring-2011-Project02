#include "line2.h"

#include <cmath>

#include "vector2.h"

Line2::Line2(void)
{
    m_startPoint = new Vector2(0, 0);
    m_endPoint = new Vector2(0, 0);
}

Line2::Line2(const Vector2& startPoint, const Vector2& endPoint)
{
    m_startPoint = new Vector2(startPoint);
    m_endPoint = new Vector2(endPoint);
}

Line2::Line2(const Line2& other)
{
    m_startPoint = new Vector2(*other.startPoint());
    m_endPoint = new Vector2(*other.endPoint());
}

Line2::~Line2(void)
{
    delete m_startPoint;
    m_startPoint = 0;

    delete m_endPoint;
    m_endPoint = 0;
}

float Line2::length(void) const
{
    float length = m_startPoint->distanceFrom(*m_endPoint);

    return length;
}

const Vector2* Line2::startPoint(void) const
{
    return m_startPoint;
}

const Vector2* Line2::endPoint(void) const
{
    return m_endPoint;
}

std::string Line2::toString(void) const
{
    std::string line2Info = "(" + m_startPoint->toString() + " - " + m_endPoint->toString() + ")";

    return line2Info;
}

std::ostream& operator << (std::ostream& out, const Line2& line2)
{
    out << line2.toString();

    return out;
}
