#include <iostream>

int main()
{

	// IMAGE

	const int img_width{ 256 };
	const int img_height{ 256 };

	// Render

	std::cout << "P3\n" << img_width << ' ' << img_height << "\n255\n";

	for (int j = 0; j < img_height; j++)
	{

		/*
		  PROGRESS INDICATOR 
		  Write to the Logging Output stream std::clog
		*/

		std::clog << "\rScanlines Left : " << (img_height - j) << ' ' << std::flush;

		for (int i = 0; i < img_width; i++)
		{

			auto r = static_cast<double>(i) / (img_width - 1);
			auto g = static_cast<double>(j) / (img_height - 1);
			auto b = 0.0;

			int ir = static_cast<int>(255.999 * r);
			int ig = static_cast<int>(255.999 * g);
			int ib = static_cast<int>(255.999 * b);

			std::cout << ir << ' ' << ig << ' ' << ib << '\n';
		}
	}

	std::clog << "\rDONE.      \n";

	/*
	 Pixels are written in Rows from Left to right and top to bottom

	 By convetion , each RGB components are represented by real valued variables that range from
	 0.0 to 1.0. So we scaled to integers values between 0 and 255 before priting them out.

	Files are written to STDOUT , we need to redirect it to an image file.

	   using Command line Redirection Operator >

	   main.exe > image.ppm
	*/
}