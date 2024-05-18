#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <string>
#include <SDL.h>
#include "IObject.hpp"
#include "../Physic/Transform.hpp"

struct Property
{
public:
	Property(std::string texture_id, int x, int y, int width, int height, SDL_RendererFlip flip = SDL_FLIP_NONE) {
		TextureID = texture_id;
		X = x;
		Y = y;
		Width = width;
		Height = height;
		Flip = flip;
	}
	std::string TextureID;
	int Width;
	int Height;
	float X, Y;
	SDL_RendererFlip Flip;
};
class GameObject :public IObject
{
public:
	GameObject(Property* prop) :m_TextureID(prop->TextureID), m_Width(prop->Width),
		m_Height(prop->Height), m_Flip(prop->Flip) {
		m_Transform = new Transform(prop->X, prop->Y);
	}

	virtual void Draw() = 0;
	virtual void Update(float dt) = 0;
	virtual void Clean() = 0;
protected:
	Transform* m_Transform;
	int m_Width;
	int m_Height;
	std::string m_TextureID;
	SDL_RendererFlip m_Flip;
};

#endif // !GAMEOBJECT_H
