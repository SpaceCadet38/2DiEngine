#ifndef WARRIOR_H
#define WARRIOR_H
#include "Character.hpp"
#include "../Animation/Animation.hpp"
#include "../Physic/RigidBody.hpp"
class Warrior :public Character
{
public:
	Warrior(Property* prop);

	virtual void Draw();
	virtual void Update(float dt);
	virtual void Clean();
private:
	//int m_Row, m_Frame, m_FrameCount, m_AnimationSpeed;
	Animation* m_Animation;
	RigidBody* m_RigidBody;
};

#endif // !WARRIOR_H
