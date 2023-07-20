#pragma once

#include <unordered_set>
#include <memory>
#include "window.h"
#include "point.h"

typedef uint16_t Tag;

class Window;

class GameObject
{
private:
	std::unordered_set<Tag> tags;

public:
	virtual void Update(double dt) = 0;
	virtual void Draw() = 0;

	void AddTag(Tag tag);
	void RemoveTag(Tag tag);
	bool HasTag(Tag tag);
};