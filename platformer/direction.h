#pragma once

#include <cmath>

typedef struct Direction
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
};

Direction GetUnitDirection(Direction direction)
{
	Direction unit_direction;

	unit_direction.x = direction.x / sqrt(pow(direction.x, 2) + pow(direction.y, 2));
	unit_direction.y = direction.y / sqrt(pow(direction.x, 2) + pow(direction.y, 2));

	return unit_direction;
}