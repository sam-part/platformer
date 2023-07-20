#include "point.h"

Point GetUnitDirection(Point direction)
{
	Point unit_direction;

	unit_direction.x = direction.x / sqrt(pow(direction.x, 2) + pow(direction.y, 2));
	unit_direction.y = direction.y / sqrt(pow(direction.x, 2) + pow(direction.y, 2));

	return unit_direction;
}

namespace Directions
{
	Point Up {0, -1};
	Point Down {0, 1};
	Point Left {-1, 0};
	Point Right {1, 0};
}