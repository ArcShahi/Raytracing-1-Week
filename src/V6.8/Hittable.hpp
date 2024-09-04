#ifndef HITTABLE_HPP
#define HITTABLE_HPP

#include "Ray.hpp"


struct Hit_record
{
	Point3 p{};
	Vec3 normal{};
	double t{};
	bool front_face{};

	void set_face_normal(const Ray& r, const Vec3& outward_normal)
	{
		// Sets the Hit Record with Normal Vector
		// Assumption : outward_noram is Unit Length

		front_face = dot(r.direction(), outward_normal) < 0;
		normal = front_face ? outward_normal : -outward_normal;
	}
};

class Hittable
{
public:
	

	virtual ~Hittable() = default;

	//virtual bool hit(const Ray& r, double ray_tmin, double ray_tmax, Hit_record& rec) const = 0;
	virtual bool hit(const Ray& r, Interval ray_t, Hit_record& rec) const = 0;

};


#endif // !HITTABLE_HPP
