#ifndef  HIT_LIST_HPP
#define  HIT_LIST_HPP





#include "Hittable.hpp"

#include <memory>
#include <vector>

class Hittalbe_List :public Hittable
{
public:

	// List of Objects in Scene
	std::vector<std::shared_ptr<Hittable>> objects;

public:
	Hittalbe_List() {}
	Hittalbe_List(std::shared_ptr<Hittable> object)
	{
		add(object);
	}

	void clear() { objects.clear(); }

	void add(std::shared_ptr<Hittable> object)
	{
		objects.push_back(object);
	}

	bool hit(const Ray& r, Interval ray_t, Hit_record& rec) const override
	{

		Hit_record temp_rec;

		bool hit_anything{ false };
		auto closest_so_far = ray_t.max;


		for (const auto& object : objects)
		{
			if (object->hit(r,Interval(ray_t.min,closest_so_far), temp_rec))
			{
				hit_anything = true;
				closest_so_far = temp_rec.t;
				rec = temp_rec;
			}
		}
		return hit_anything;
	}



};
#endif // ! HIT_LIST_HPP