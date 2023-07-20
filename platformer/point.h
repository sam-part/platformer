#pragma once

#include "direction.h"

struct Point
{
	double x;
	double y;

	Point& operator + (const Direction& other)
	{
		x += other.x;
		y += other.y;

		return *this;
	}

	Point& operator += (const Direction& other)
	{
		x += other.x;
		y += other.y;

		return *this;
	}

	Point& operator - (const Direction& other)
	{
		x -= other.x;
		y -= other.y;

		return *this;
	}

	Point& operator -= (const Direction& other)
	{
		x -= other.x;
		y -= other.y;

		return *this;
	}
};