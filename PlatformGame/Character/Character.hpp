#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include "../Object/GameObject.hpp"
class Character:public GameObject
{
public:
	Character(Property* prop) : GameObject(prop) {};
	virtual void Draw() = 0;
	virtual void Update(float dt) = 0;
	virtual void Clean() = 0;

private:
	std::string m_Name;
};

#endif // !CHARACTER_H
