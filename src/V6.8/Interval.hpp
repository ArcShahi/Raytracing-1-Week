#ifndef INTERVAL_HPP
#define INTERVAL_HPP

constexpr double inf{ std::numeric_limits<double>::infinity() };

class Interval
{
public:
	Interval() 
		:min{ +inf },max{-inf}
	{}
	Interval(double mn, double mx)
		:min{ min }, max{ mx }
	{

	}

	double size()const
	{
		return max - min;
	}

	bool contains(double x) const
	{
		return min <= x && x <= max;
	}

	bool surrounds(double x)const
	{
		return min < x && x < max;
	}

	static const Interval empty, universe;

	

public:
	double min{};
	double max{};

};

const Interval Interval::empty = Interval(+inf, -inf);
const Interval Interval::universe = Interval(-inf, +inf);

#endif // !INTERVAL_HPP
