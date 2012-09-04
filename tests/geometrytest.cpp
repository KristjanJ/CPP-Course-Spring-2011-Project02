#include <iostream>
#include <sstream>
#include <cstdlib>

#include "geometry.h"

void testLibraryBasic(void);
void test2DGeometry(void);
void test3DGeometry(void);

int main(void)
{
    testLibraryBasic();
    test2DGeometry();
    std::cout << "\n" << std::endl;
    test3DGeometry();

    return EXIT_SUCCESS;
}

void testLibraryBasic(void)
{
    using namespace std;

	ostringstream oss;
	// Vector2
	// Require default constructor
	Vector2 v1;
	// Require public coordinates x and y
	oss << v1.x << v1.y;
	// Require constructor with two parameters
	Vector2 v2 (1.0, -1.0);
	// Require distanceFrom method
	float f = v1.distanceFrom(v2);
	// Require operator <<
	oss << v1 << endl;

	// Line2
	// Require default constructor
	Line2 l1;
	// Require constructor with two parameters
	Line2 l2 (v1, v2);
	// Require method length
	f = l1.length();
	// Require operator <<
	oss << l1 << endl;

    // Circle2
	// Require default constructor
    Circle2 c1;
	// Require constructor with vector and a radius
    Circle2 c2 (v1, 1.0);
	// Require method circumference
	f = c1.circumference();
	// Require method area
	f = c1.area();
	// Require method contains(Vector2)
	bool b = c1.contains(v1);
	// Require method contains(Line2)
	b = c1.contains(l1);
	// Require method scale
    c1.scale(1.0);
	// Require operator <<
	oss << c1 << endl;

	//Remove this comment to test the bonus task

    // Vector3
	// Require default constructor
	Vector3 v3_1;
	// Require public coordinates x, y and z
	oss << v3_1.x << v3_1.y << v3_1.z;
	// Require constructor with three parameters
	Vector3 v3_2 (1.0, 0.0, -1.0);
	// Requre method distanceFrom
	f = v3_1.distanceFrom (v3_2);
	// Require operator <<
    oss << v3_1;

	// Line2
	// Require default constructor
	Line3 l3_1;
	// Require constructor with two parameters
	Line3 l3_2 (v3_1, v3_2);
	// Require method length
	f = l3_1.length();
	// Require operator <<
	oss << l3_1 << endl;

    // Sphere3
	// Require default constructor
    Sphere3 s3_1;
	// Require constructor with vector and a radius
    Sphere3 s3_2 (v3_1, 1.0);
	// Require method circumference
	f = s3_1.circumference();
	// Require method volume
	f = s3_1.volume();
	// Require method contains(Vector2)
	b = s3_1.contains(v3_1);
	// Require method contains(Line3)
	b = s3_1.contains(l3_1);
	// Require method scale
    s3_1.scale(1.0);
	// Require operator <<
	oss << s3_1 << endl;

	//Remove this comment to test the bonus task
}

void test2DGeometry(void)
{
    Vector2 vec1(10.5, 20.5);
    Vector2 vec2(20.5, 40.5);
    Vector2 vec3(15.5, 25.5);
    Line2 line1(vec1, vec2);
    Line2 line2(vec1, vec3);
    Circle2 circle(vec1, 10.5);

    std::cout << "TESTING VECTOR2\n" << std::endl;
    std::cout << "VEC1: " << vec1 << std::endl;
    std::cout << "VEC2: " << vec2 << std::endl;
    std::cout << "VEC3: " << vec3 << std::endl;
    std::cout << "DISTANCE V1 - V2: " << vec1.distanceFrom(vec2) << std::endl;
    std::cout << "DISTANCE V2 - V1: " << vec2.distanceFrom(vec1) << std::endl;
    std::cout << "DISTANCE V1 - V1: " << vec1.distanceFrom(vec1) << std::endl;
    std::cout << "DISTANCE V2 - V2: " << vec2.distanceFrom(vec2) << std::endl;

    std::cout << "\n\nTESTING LINE2\n" << std::endl;
    std::cout << "LINE1: " << line1 << std::endl;
    std::cout << "LENGTH L1: " << line1.length() << std::endl;
    std::cout << "LINE2: " << line2 << std::endl;
    std::cout << "LENGTH L2: " << line2.length() << std::endl;

    std::cout << "\n\nTESTING CIRCLE2\n" << std::endl;
    std::cout << "CIRCLE: " << circle << std::endl;
    std::cout << "CIRCUMFERENCE: " << circle.circumference() << std::endl;
    std::cout << "AREA: " << circle.area() << std::endl;
    bool contains1 = circle.contains(vec1);
    bool contains2 = circle.contains(vec2);
    bool contains3 = circle.contains(vec3);
    bool contains4 = circle.contains(line1);
    bool contains5 = circle.contains(line2);
    std::cout << "CONTAINS V1 - V2 - V3 - L1 - L2: " << std::boolalpha << contains1 << " - "
        << contains2 << " - " << contains3 << " - " << contains4 << " - " << contains5 << std::endl;

    circle.scale(2.5);
    std::cout << "\n\nTESTING CIRCLE2 after scaling with 2.5\n" << std::endl;
    std::cout << "CIRCLE: " << circle << std::endl;
    std::cout << "CIRCUMFERENCE: " << circle.circumference() << std::endl;
    std::cout << "AREA: " << circle.area() << std::endl;
    contains1 = circle.contains(vec1);
    contains2 = circle.contains(vec2);
    contains3 = circle.contains(vec3);
    contains4 = circle.contains(line1);
    contains5 = circle.contains(line2);
    std::cout << "CONTAINS V1 - V2 - V3 - L1 - L2: " << std::boolalpha << contains1 << " - "
        << contains2 << " - " << contains3 << " - " << contains4 << " - " << contains5 << std::endl;
}

void test3DGeometry(void)
{
    Vector3 vec1(10.5, 20.5, 40.5);
    Vector3 vec2(20.5, 40.5, 80.5);
    Vector3 vec3(15.5, 25.5, 45.5);
    Line3 line1(vec1, vec2);
    Line3 line2(vec1, vec3);
    Sphere3 sphere(vec1, 10.5);

    std::cout << "TESTING VECTOR3\n" << std::endl;
    std::cout << "VEC1: " << vec1 << std::endl;
    std::cout << "VEC2: " << vec2 << std::endl;
    std::cout << "VEC3: " << vec3 << std::endl;
    std::cout << "DISTANCE V1 - V2: " << vec1.distanceFrom(vec2) << std::endl;
    std::cout << "DISTANCE V2 - V1: " << vec2.distanceFrom(vec1) << std::endl;
    std::cout << "DISTANCE V1 - V1: " << vec1.distanceFrom(vec1) << std::endl;
    std::cout << "DISTANCE V2 - V2: " << vec2.distanceFrom(vec2) << std::endl;

    std::cout << "\n\nTESTING LINE3\n" << std::endl;
    std::cout << "LINE1: " << line1 << std::endl;
    std::cout << "LENGTH L1: " << line1.length() << std::endl;
    std::cout << "LINE2: " << line2 << std::endl;
    std::cout << "LENGTH L2: " << line2.length() << std::endl;

    std::cout << "\n\nTESTING SPHERE3\n" << std::endl;
    std::cout << "SPHERE: " << sphere << std::endl;
    std::cout << "CIRCUMFERENCE: " << sphere.circumference() << std::endl;
    std::cout << "AREA: " << sphere.area() << std::endl;
    std::cout << "VOLUME: " << sphere.volume() << std::endl;
    bool contains1 = sphere.contains(vec1);
    bool contains2 = sphere.contains(vec2);
    bool contains3 = sphere.contains(vec3);
    bool contains4 = sphere.contains(line1);
    bool contains5 = sphere.contains(line2);
    std::cout << "CONTAINS V1 - V2 - V3 - L1 - L2: " << std::boolalpha << contains1 << " - "
        << contains2 << " - " << contains3 << " - " << contains4 << " - " << contains5 << std::endl;

    sphere.scale(8.0);
    std::cout << "\n\nTESTING SPHERE3 after scaling with 8.0\n" << std::endl;
    std::cout << "SPHERE: " << sphere << std::endl;
    std::cout << "CIRCUMFERENCE: " << sphere.circumference() << std::endl;
    std::cout << "AREA: " << sphere.area() << std::endl;
    std::cout << "VOLUME: " << sphere.volume() << std::endl;
    contains1 = sphere.contains(vec1);
    contains2 = sphere.contains(vec2);
    contains3 = sphere.contains(vec3);
    contains4 = sphere.contains(line1);
    contains5 = sphere.contains(line2);
    std::cout << "CONTAINS V1 - V2 - V3 - L1 - L2: " << std::boolalpha << contains1 << " - "
        << contains2 << " - " << contains3 << " - " << contains4 << " - " << contains5 << std::endl;
}
