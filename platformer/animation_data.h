#pragma once

#include "dimensions.h"

struct AnimationData {
	Dimensions texture_dimensions;
	Dimensions player_dimensions;
	int frame;
	double running_time;
	double update_time;
};