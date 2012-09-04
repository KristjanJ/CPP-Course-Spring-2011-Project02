#ifndef LINE2_H_INCLUDED
#define LINE2_H_INCLUDED

#include <iosfwd>
#include <string>

class Vector2;

/*!
\brief A 2D line.
*/
class Line2
{
public:
    /*!
    \details Default constructor. Constructs a line with the length of zero.
    */
    Line2(void);

    /*!
    \details Constructs a line of two vectors.
    \param startPoint Starting point.
    \param endPoint Ending point.
    */
    Line2(const Vector2& startPoint, const Vector2& endPoint);

    /*!
    \details Constructs a line from another line.
    \param other Another line.
    */
    Line2(const Line2& other);

    /*!
    \details Destructs a line.
    */
    ~Line2(void);

    /*!
    \details Returns the length of this line.
    \returns The length of this line.
    */
    float length(void) const;

    /*!
    \details Returns the starting point of this line.
    \returns The starting point of this line.
    */
    const Vector2* startPoint(void) const;

    /*!
    \details Returns the ending point of this line.
    \returns The ending point of this line.
    */
    const Vector2* endPoint(void) const;

    /*!
    \details Returns the string representation of this line.
    \returns The string representation of this line.
    */
    std::string toString(void) const;

private:
    Vector2* m_startPoint;
    Vector2* m_endPoint;
};

std::ostream& operator << (std::ostream& out, const Line2& line2);

#endif // LINE2_H_INCLUDED
