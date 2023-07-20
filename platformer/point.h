#pragma once

#include <cmath>
#include <map>

struct Point
{
	double x;
	double y;

	bool operator == (const Point& other)
	{
		return x == other.x && y == other.y;
	}

	Point& operator = (const Point& other)
	{
		x = other.x;
		y = other.y;
		return *this;
	}

	Point& operator + (const Point& other)
	{
		x + other.x;
		y + other.y;
		return *this;
	}

	Point& operator += (const Point& other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}

	Point& operator - (const Point& other)
	{
		x - other.x;
		y - other.y;
		return *this;
	}

	Point& operator -= (const Point& other)
	{
		x -= other.x;
		y -= other.y;
		return *this;
	}

	Point& operator * (const double& other)
	{
		x *= other;
		y *= other;
		return *this;
	}
};

Point GetUnitDirection(Point direction)
{
	Point unit_direction;

	unit_direction.x = direction.x / sqrt(pow(direction.x, 2) + pow(direction.y, 2));
	unit_direction.y = direction.y / sqrt(pow(direction.x, 2) + pow(direction.y, 2));

	return unit_direction;
}

Point Directions(const char* direction)
{
	std::map<const char*, Point>directions;

	directions["d_up"] = { 0, -1 };
	directions["d_down"] = { 0, 1 };
	directions["d_left"] = { -1, 0 };
	directions["d_right"] = { 1, 0 };

	return directions[direction];
}