#pragma once

#include <unordered_set>

typedef uint16_t Tag;

class GameObject
{
private:
	std::unordered_set<Tag> tags;

public:
	virtual void Update(double dt);
	virtual void Draw();

	void AddTag(Tag tag);
	void RemoveTag(Tag tag);
	bool HasTag(Tag tag);
};