#ifndef CORE_HPP
#define CORE_HPP

#include <cmath>
#include <iostream>
#include <limits>
#include <memory>

// OUR HEADERS

#include "Color.hpp"
#include "Ray.hpp"
#include "Vec3.hpp"
#include "Interval.hpp"



// CONSANTS

constexpr double infinity{ std::numeric_limits<double>::infinity() };
constexpr double PI{ 3.141592653589793285 };

// UTILITY

inline double to_radian(double degrees)
{
	return degrees * PI / 180.0;

}

#endif // 
