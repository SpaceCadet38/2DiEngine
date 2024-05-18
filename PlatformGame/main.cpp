#include<iostream>
#include "Core/Engine.hpp"
#include "Timer/Timer.hpp"
int main(int argc, char* args[])
{
	Engine::GetInstance()->Init();

	while (Engine::GetInstance()->IsRunning())
	{
		Engine::GetInstance()->Event();
		Engine::GetInstance()->Update();
		Engine::GetInstance()->Render();
		Timer::GetInstance()->GetTick();
	}
	Engine::GetInstance()->Clean();
	return 0;
}