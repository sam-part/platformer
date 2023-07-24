#pragma once

#include "point.h"

struct Movement
{
	double velocity;
	double speed;
	double acceleration;
	Point direction;
	Point position;
};