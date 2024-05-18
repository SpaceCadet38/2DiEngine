#include "Timer.hpp"
#include <SDL.h>

Timer* Timer::s_Instance = nullptr;

Timer::Timer()
{
	m_DeltaTime = 0.0f;
	m_LastTime = 0.0f;
}

void Timer::GetTick()
{
	m_DeltaTime = (SDL_GetTicks() - m_LastTime) * (FPS / 1000.0f);
	if (m_DeltaTime > DELTA_TIME)
	{
		m_DeltaTime = DELTA_TIME;
	}
	m_LastTime = SDL_GetTicks();
}
