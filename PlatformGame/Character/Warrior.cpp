#include "Warrior.hpp"
#include "../Graphic/TextureManager.hpp"
#include "../Input/Input.hpp"
#include "SDL.h"

Warrior::Warrior(Property* prop) :Character(prop)
{
	m_Animation = new Animation();
	m_RigidBody = new RigidBody();
	m_Animation->SetProp(m_TextureID, 0, 6, 100, SDL_FLIP_NONE);
}

void Warrior::Draw()
{
	m_Animation->Draw(m_Transform->X, m_Transform->Y, m_Width, m_Height);
}

void Warrior::Update(float dt)
{
	m_Animation->SetProp(m_TextureID, 0, 6, 100, SDL_FLIP_NONE);
	m_RigidBody->UnsetForce();
	if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_A))
	{
		m_RigidBody->ApplyForceX(5 * BACKWARD);

		m_Animation->SetProp(m_TextureID, 1, 6, 100, SDL_FLIP_HORIZONTAL);
	}
	if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_D))
	{
		m_RigidBody->ApplyForceX(5 * FORWARD);
		m_Animation->SetProp(m_TextureID, 1, 6, 100, SDL_FLIP_NONE);
	}
	SDL_Log("%f", dt);
	m_RigidBody->Update(0.8);
	m_Transform->TranslateX(m_RigidBody->Position().X);
	//m_Transform->TranslateY(m_RigidBody->Position().Y);
	m_Animation->Update();
}

void Warrior::Clean()
{
	TextureManager::GetInstance()->Clean();
}
