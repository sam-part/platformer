#pragma once

#include <unordered_set>
#include <memory>
#include "window.h"

typedef uint16_t Tag;

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