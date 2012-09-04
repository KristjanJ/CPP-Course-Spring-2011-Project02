#ifndef CIRCLE2_H_INCLUDED
#define CIRCLE2_H_INCLUDED

#include <iosfwd>
#include <string>

class Vector2;
class Line2;

/*!
\brief A 2D circle.
*/
class Circle2
{
public:
    /*!
    \details Default constructor. Constructs a circle with a center point and radius of zero.
    */
    Circle2(void);

    /*!
    \details Constructs a circle with a given center point and radius. If a negative radius is given, it will default to 0.
    \param center Center point.
    \param radius Radius.
    */
    Circle2(const Vector2& center, float radius);

    /*!
    \details Constructs a circle from another circle.
    \param other Another circle.
    */
    Circle2(const Circle2& other);

    /*!
    \details Destructs a circle.
    */
    ~Circle2(void);

    /*!
    \details Returns the circumference of this circle.
    \returns The circumference of this circle.
    */
    float circumference(void) const;

    /*!
    \details Returns the area of this circle.
    \returns The area of this circle.
    */
    float area(void) const;

    /*!
    \details Returns the center of this circle.
    \returns The center of this circle.
    */
    const Vector2* center(void) const;

    /*!
    \details Returns the radius of this circle.
    \returns The radius of this circle.
    */
    float radius(void) const;

    /*!
    \details Checks if this circle contains a given point.
    \param point A point.
    \returns true if the point is inside the circle, otherwize false.
    */
    bool contains(const Vector2& point) const;

    /*!
    \details Checks if this circle contains a given line.
    \param line A line.
    \returns true if the line is inside the circle, otherwize false.
    */
    bool contains(const Line2& line) const;

    /*!
    \details Returns the string representation of this circle.
    \returns The string representation of this circle.
    */
    std::string toString(void) const;

    /*!
    \details Scales this circle to a new size. If a negative factor is given no scaling will be performed.
    \param factor Radius multiplier.
    */
    void scale(float factor);

private:
    Vector2* m_center;
    float m_radius;
};

std::ostream& operator << (std::ostream& out, const Circle2& circle2);

#endif // CIRCLE2_H_INCLUDED
