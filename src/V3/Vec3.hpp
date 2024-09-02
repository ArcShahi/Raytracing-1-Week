#ifndef VEC3_HPP
#define VEC3_HPP

#include <cmath>
#include <iostream>

class Vec3
{
public:
     double e[3];

public:
     Vec3() : e{ 0, 0, 0 } {}
     Vec3(double e0, double e1, double e2) : e{ e0, e1, e2 } {}

     double x() const { return e[0]; }
     double y() const { return e[1]; }
     double z() const { return e[2]; }

     // Overloading the Negation Operator
     Vec3 operator-() const
     {
          return Vec3(-e[0], -e[1], -e[2]);
     }

     // Overloading the index Operator
     double operator[](int i) const { return e[i]; }
     double& operator[](int i) { return e[i]; }

     // Overloading += operator
     Vec3& operator+=(const Vec3& v)
     {
          e[0] += v.e[0];
          e[1] += v.e[1];
          e[2] += v.e[2];
          return *this;
     }

     // Overloading *= operator
     Vec3& operator*=(double t)
     {
          e[0] *= t;
          e[1] *= t;
          e[2] *= t;
          return *this;
     }

     Vec3& operator/=(double t)
     {
          if (t != 0)
          {
               *this *= (1 / t);
          }
          else
          {
               throw std::invalid_argument("Division by zero is not allowed.");
          }
          return *this;
     }

     double length() const
     {
          return std::sqrt(length_sq());
     }

     double length_sq() const
     {
          return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
     }
};

using Point3 = Vec3;

// Inlining it because it's going to be included in multiple files

// Utility Function Overloading Arithmetic and Output Operator
inline std::ostream& operator<<(std::ostream& out, const Vec3& v)
{
     return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

// Overloading for addition
inline Vec3 operator+(const Vec3& u, const Vec3& v)
{
     return Vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

// Overloading for subtraction
inline Vec3 operator-(const Vec3& u, const Vec3& v)
{
     return Vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

// Overloading for component-wise multiplication
inline Vec3 operator*(const Vec3& u, const Vec3& v)
{
     return Vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

// Overloading for scalar multiplication
inline Vec3 operator*(double t, const Vec3& v)
{
     return Vec3(t * v.e[0], t * v.e[1], t * v.e[2]);
}

// Corrected the scalar multiplication
inline Vec3 operator*(const Vec3& v, double t)
{
     return t * v;
}

// Overloading for scalar division
inline Vec3 operator/(const Vec3& v, double t)
{
     if (t != 0)
     {
          return (1 / t) * v;
     }
     else
     {
          throw std::invalid_argument("Division by zero is not allowed.");
     }
}

// Dot product
inline double dot(const Vec3& u, const Vec3& v)
{
     return u.e[0] * v.e[0] + u.e[1] * v.e[1] + u.e[2] * v.e[2];
}

// Cross product
inline Vec3 cross(const Vec3& u, const Vec3& v)
{
     return Vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
          u.e[2] * v.e[0] - u.e[0] * v.e[2],
          u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

// Unit vector
inline Vec3 unit_vector(const Vec3& v)
{
     return v / v.length();
}

#endif // !VEC3_HPP
