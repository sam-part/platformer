#pragma once

#include "point.h"

struct AnimationData {
	Point texture_dimensions;
	Point player_dimensions;
	int frame;
	double running_time;
	double update_time;
};