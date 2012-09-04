#ifndef LINE3_H_INCLUDED
#define LINE3_H_INCLUDED

#include <iosfwd>
#include <string>

class Vector3;

/*!
\brief A 3D line.
*/
class Line3
{
public:
    /*!
    \details Default constructor. Constructs a line with the length of 0.
    */
    Line3(void);

    /*!
    \details Constructs a line of two vectors.
    \param startPoint Starting point.
    \param endPoint Ending point.
    */
    Line3(const Vector3& startPoint, const Vector3& endPoint);

    /*!
    \details Constructs a line from another line.
    \param other Another line.
    */
    Line3(const Line3& other);

    /*!
    \details Destructs a line.
    */
    ~Line3(void);

    /*!
    \details Returns the length of this line.
    \returns The length of this line.
    */
    float length(void) const;

    /*!
    \details Returns the starting point of this line.
    \returns The starting point of this line.
    */
    const Vector3* startPoint(void) const;

    /*!
    \details Returns the ending point of this line.
    \returns The ending point of this line.
    */
    const Vector3* endPoint(void) const;

    /*!
    \details Returns the string representation of this line.
    \returns The string representation of this line.
    */
    std::string toString(void) const;

private:
    Vector3* m_startPoint;
    Vector3* m_endPoint;
};

std::ostream& operator << (std::ostream& out, const Line3& line3);

#endif // LINE3_H_INCLUDED
