﻿#include "Color.hpp"
#include "Ray.hpp"
#include "Vec3.hpp"

#include <iostream>

bool hit_sphere(const Point3& center, double radius, const Ray& r)
{
      
     /*
     * Formula for Collision Detection
     * 
      Any Point P that satisfies :
       (Center - Point ) .(dot) ( Center - Point ) = Radius^2 

       is on the sphere.

       If our Ray P(t)= satisfies that equantion , we wanna knnow for any 't' this it true

       ( C-P(t)) . ( C-P(t)) = r^2

     */
     Vec3 oc = center - r.origin();
     auto a = dot(r.direction(), r.direction());
     auto b = -2.0 * dot(r.direction(), oc);
     auto c = dot(oc, oc) - radius * radius;
     auto discriminant = b * b - 4 * a * c;

     return (discriminant >= 0);

}


Color ray_color(const Ray& r) 
{ 

     // Our Circle is On -1 on Z axis ( view direction ) 
     if (hit_sphere(Point3(0, 0, -1), 0.5, r))
     {
          return Color(1, 0, 0); // Red Color
     }

     // If Not Interacted With Circle Default Color Returned
     Vec3 unit_direction = unit_vector(r.direction());
     auto a = 0.5 * (unit_direction.y() + 1.0);
     return (1.0 - a) * Color(1.0, 1.0, 1.0) + a * Color(0.5, 0.7, 1.0);
}


int main() {

     // Image

     auto aspect_ratio = 16.0 / 9.0;
     int image_width = 400;

     // Calculate the image height, and ensure that it's at least 1.
     int image_height = int(image_width / aspect_ratio);
     image_height = (image_height < 1) ? 1 : image_height;

     // Camera

     auto focal_length = 1.0;
     auto viewport_height = 2.0;
     auto viewport_width = viewport_height * static_cast<double>(image_width) / image_height;
     auto camera_center = Point3(0, 0, 0);

     // Calculate the vectors across the horizontal and down the vertical viewport edges.
     auto viewport_u = Vec3(viewport_width, 0, 0);
     auto viewport_v = Vec3(0, -viewport_height, 0);

     // Calculate the horizontal and vertical delta vectors from pixel to pixel.
     auto pixel_delta_u = viewport_u / image_width;
     auto pixel_delta_v = viewport_v / image_height;

     // Calculate the location of the upper left pixel.
     auto viewport_upper_left = camera_center
          - Vec3(0, 0, focal_length) - viewport_u / 2 - viewport_v / 2;
     auto pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

     // Render

     std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";

     for (int j = 0; j < image_height; j++) {
          std::clog << "\rSCANLINES LEFT: " << (image_height - j) << ' ' << std::flush;
          for (int i = 0; i < image_width; i++) {
               Vec3 pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
               Vec3 ray_direction = pixel_center - camera_center;
               Ray r(camera_center, ray_direction);

               Color pixel_color = ray_color(r);
               write_color(std::cout, pixel_color);
          }
     }

     std::clog << "\rDone.                 \n";
}