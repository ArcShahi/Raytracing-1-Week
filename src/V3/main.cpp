#include <iostream>

#include "Vec3.hpp"
#include "Color.hpp"


int main()
{

	// IMAGE

	const int img_width{ 256 };
	const int img_height{ 256 };

	// Render

	std::cout << "P3\n" << img_width << ' ' << img_height << "\n255\n";

	for (int j = 0; j < img_height; j++)
	{

		

		std::clog << "\rScanlines Left : " << (img_height - j) << ' ' << std::flush;

		for (int i = 0; i < img_width; i++)
		{


			Color pixel_Color = Color(static_cast<double>(i) / (img_width - 1),
				                  static_cast<double>(j) / (img_height - 1), 0);
			write_color(std::cout, pixel_Color);
		}
	}

	std::clog << "\rDONE.                \n" << std::flush;


}