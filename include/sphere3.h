#ifndef SPHERE3_H_INCLUDED
#define SPHERE3_H_INCLUDED

#include <iosfwd>
#include <string>

class Vector3;
class Line3;

/*!
\brief A 3D sphere.
*/
class Sphere3
{
public:
    /*!
    \details Default constructor. Constructs a sphere with a center point and radius of zero.
    */
    Sphere3(void);

    /*!
    \details Constructs a sphere with a given center point and radius. If a negative radius is given, it will default to 0.
    \param center Center point.
    \param radius Radius.
    */
    Sphere3(const Vector3& center, float radius);

    /*!
    \details Constructs a sphere from another sphere.
    \param other Another sphere.
    */
    Sphere3(const Sphere3& other);

    /*!
    \details Destructs a sphere.
    */
    ~Sphere3(void);

    /*!
    \details Returns the circumference of this sphere.
    \returns The circumference of this sphere.
    */
    float circumference(void) const;

    /*!
    \details Returns the area of this sphere.
    \returns The area of this sphere.
    */
    float area(void) const;

    /*!
    \details Returns the volume of this sphere.
    \returns The volume of this sphere.
    */
    float volume(void) const;

    /*!
    \details Returns the center of this circle.
    \returns The center of this circle.
    */
    const Vector3* center(void) const;

    /*!
    \details Returns the radius of this circle.
    \returns The radius of this circle.
    */
    float radius(void) const;

    /*!
    \details Checks if this sphere contains a given point.
    \param point A point.
    \returns true if the point is inside the sphere, otherwize false.
    */
    bool contains(const Vector3& point) const;

    /*!
    \details Checks if this sphere contains a given line.
    \param line A line.
    \returns true if the line is inside the sphere, otherwize false.
    */
    bool contains(const Line3& line) const;

    /*!
    \details Returns the string representation of this sphere.
    \returns The string representation of this sphere.
    */
    std::string toString(void) const;

    /*!
    \details Scales this sphere to a new size. If a negative factor is given no scaling will be performed.
    \param factor Radius multiplier.
    */
    void scale(float factor);

private:
    Vector3* m_center;
    float m_radius;
};

std::ostream& operator << (std::ostream& out, const Sphere3& sphere3);

#endif // SPHERE3_H_INCLUDED
