#pragma once

#include <cmath>
#include <map>

struct Direction
{
	double x;
	double y;

	bool operator == (const Direction& other)
	{
		return x == other.x && y == other.y;
	}

	Direction& operator = (const Direction& other)
	{
		x = other.x;
		y = other.y;
		return *this;
	}

	Direction& operator + (const Direction& other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}

	Direction& operator - (const Direction& other)
	{
		x -= other.x;
		y -= other.y;
		return *this;
	}

	Direction& operator * (const double& other)
	{
		x *= other;
		y *= other;
		return *this;
	}
};


Direction GetUnitDirection(Direction direction)
{
	Direction unit_direction;

	unit_direction.x = direction.x / sqrt(pow(direction.x, 2) + pow(direction.y, 2));
	unit_direction.y = direction.y / sqrt(pow(direction.x, 2) + pow(direction.y, 2));

	return unit_direction;
}

Direction Directions(const char* direction)
{
	std::map<const char*, Direction>directions;

	directions["d_up"] = { 0, -1 };
	directions["d_down"] = { 0, 1 };
	directions["d_left"] = { -1, 0 };
	directions["d_right"] = { 1, 0 };

	return directions[direction];
}