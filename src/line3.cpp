#include "line3.h"

#include <cmath>

#include "vector3.h"

Line3::Line3(void)
{
    m_startPoint = new Vector3(0, 0, 0);
    m_endPoint = new Vector3(0, 0, 0);
}

Line3::Line3(const Vector3& startPoint, const Vector3& endPoint)
{
    m_startPoint = new Vector3(startPoint);
    m_endPoint = new Vector3(endPoint);
}

Line3::Line3(const Line3& other)
{
    m_startPoint = new Vector3(*other.startPoint());
    m_endPoint = new Vector3(*other.endPoint());
}

Line3::~Line3(void)
{
    delete m_startPoint;
    m_startPoint = 0;

    delete m_endPoint;
    m_endPoint = 0;
}

float Line3::length(void) const
{
    float length = m_startPoint->distanceFrom(*m_endPoint);

    return length;
}

const Vector3* Line3::startPoint(void) const
{
    return m_startPoint;
}

const Vector3* Line3::endPoint(void) const
{
    return m_endPoint;
}

std::string Line3::toString(void) const
{
    std::string line2Info = "(" + m_startPoint->toString() + " - " + m_endPoint->toString() + ")";

    return line2Info;
}

std::ostream& operator << (std::ostream& out, const Line3& line3)
{
    out << line3.toString();

    return out;
}
