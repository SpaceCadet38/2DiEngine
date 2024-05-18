#include "Engine.hpp"
#include "../Graphic/TextureManager.hpp"
#include <iostream>
#include "../Physic/Vector2D.hpp"
#include "../Physic/Transform.hpp";
#include "../Character/Warrior.hpp"
#include "../Input/Input.hpp"
#include "../Timer/Timer.hpp"
Engine* Engine::s_Instance = nullptr;
Warrior* player = nullptr;

Engine::Engine()
{
}

bool Engine::Init() {
	if (SDL_Init(SDL_INIT_VIDEO) != 0 && IMG_Init(IMG_INIT_PNG) != 0)
	{
		SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
		return false;
	}
	m_Window = SDL_CreateWindow("Platform", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
	if (m_Window == nullptr)
	{
		SDL_Log("Failed to create window: %s", SDL_GetError());
		return false;
	}
	m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (m_Renderer == nullptr)
	{
		return false;
	}

	TextureManager::GetInstance()->Load("player", "asset/Warrior_Red.png");
	player = new Warrior(new Property("player", 100, 200, 192, 192));
	return m_IsRunning = true;
}

void Engine::Update() {
	float delta_time = Timer::GetInstance()->GetDeltaTime();
	player->Update(delta_time); 
}

void Engine::Render() {
	SDL_SetRenderDrawColor(m_Renderer, 124, 218, 254, 255);
	SDL_RenderClear(m_Renderer);
	player->Draw();
	SDL_RenderPresent(m_Renderer);
}

void Engine::Event() {
	Input::GetInstance()->Listen();
}

bool Engine::Clean() {
	TextureManager::GetInstance()->Clean();
	SDL_DestroyRenderer(m_Renderer);
	SDL_DestroyWindow(m_Window);
	IMG_Quit();
	SDL_Quit();
	return true;
}

void Engine::Quit() {
	m_IsRunning = false;
}