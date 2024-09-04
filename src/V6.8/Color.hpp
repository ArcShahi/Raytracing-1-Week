#ifndef  COLOR_HPP
#define  COLOR_HPP


#include "Vec3.hpp"

#include <iostream>


using Color = Vec3;

void write_color(std::ostream& out, const Color& pixel_color)
{
	auto r = pixel_color.x();
	auto g = pixel_color.y();
	auto b = pixel_color.z();

	// Translate the [0,1] component Values to The Byte Range [ 0,255]

	int rByte = static_cast<int>(255.999 * r);
	int gByte = static_cast<int>(255.999 * g);
	int bByte = static_cast<int>(255.999 * b);

	// Write out the Pixel Color Components
	out << rByte << ' ' << gByte << ' ' << bByte << '\n';
}

#endif // ! COLOR_HPP



