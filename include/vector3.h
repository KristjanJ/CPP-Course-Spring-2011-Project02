#ifndef VECTOR3_H_INCLUDED
#define VECTOR3_H_INCLUDED

#include <iosfwd>
#include <string>

/*!
\brief A 3D vector.
*/
class Vector3
{
public:
    /*!
    \details X coordinate of this vector.
    */
	float x;

	/*!
    \details Y coordinate of this vector.
    */
	float y;

	/*!
    \details Z coordinate of this vector.
    */
	float z;

    /*!
    \details Default constructor. Constructs a null vector.
    */
	Vector3(void);

	/*!
    \details Constructs a vector with the coordinates x, y and z.
    \param x X coordinate.
    \param y Y coordinate.
    \param z Z coordinate.
    */
	Vector3(float x, float y, float z);

	/*!
    \details Copy constructor. Constructs a vector from another vector.
    \param other Another vector.
    */
	Vector3(const Vector3& other);

	/*!
    \details Destructs a vector.
    */
	~Vector3(void);

    /*!
    \details Returns the distance between this vector and an another vector.
    \param other Another vector.
    \returns The distance between this vector and an another vector.
    */
	float distanceFrom(const Vector3& other) const;

	/*!
    \details Returns a string representation of this vector.
    \returns A string representation of this vector.
    */
	std::string toString(void) const;
};

std::ostream& operator << (std::ostream& out, const Vector3& vector3);

#endif // VECTOR3_H_INCLUDED
