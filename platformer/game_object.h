#pragma once

#include <unordered_set>
#include <memory>

typedef uint16_t Tag;

class Window;

class GameObject
{
private:
	std::unordered_set<Tag> tags;

public:
	virtual void Update(double dt) = 0;
	virtual void Draw(Window& window) = 0;

	void AddTag(Tag tag);
	void RemoveTag(Tag tag);
	bool HasTag(Tag tag);
};