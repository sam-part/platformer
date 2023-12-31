#pragma once

#include <cmath>
#include <map>

struct Point
{
	double x;
	double y;

	bool operator == (const Point& other)
	{
		return (x == other.x && y == other.y);
	}

	Point operator + (const Point& other)
	{
		return Point(x + other.x, y + other.y);
	}

	Point& operator += (const Point& other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}

	Point operator - (const Point& other)
	{
		return Point(x - other.x, y - other.y);
	}

	Point& operator -= (const Point& other)
	{
		x -= other.x;
		y -= other.y;
		return *this;
	}

	Point operator * (const double& scalar)
	{
		return Point(x * scalar, y * scalar);
	}
};

Point GetUnitDirection(Point direction);

namespace Directions
{
	extern Point Up;
	extern Point Down;
	extern Point Left; 
	extern Point Right;
}