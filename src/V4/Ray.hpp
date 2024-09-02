#ifndef RAY_HPP
#define RAY_HPP

#include "Vec3.hpp"

class Ray 
{
public:
	Ray() {};
	Ray(const Point3& origin, const Vec3& direction)
		:orig(origin), dir(direction)
	{}
	// Return const reference to Member Variables ( can be used directly or copied to a mutable object)
	const Point3& origin()const { return orig; }
	const Vec3& direction()const { return dir; }

	Point3 at(double t)const
	{

		// P(T) = A + tB
		// A- Ray Orign , B- Ray Direction
		return orig + t * dir;
	}


public:
	Point3 orig;
	Vec3 dir;
};
#endif // !RAYLIB_HPP
