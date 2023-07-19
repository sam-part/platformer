#include "game_object.h"

void GameObject::AddTag(Tag tag)
{
	tags.insert(tag);
}

void GameObject::RemoveTag(Tag tag)
{
	tags.erase(tag);
}

bool GameObject::HasTag(Tag tag)
{
	return tags.contains(tag);
}
