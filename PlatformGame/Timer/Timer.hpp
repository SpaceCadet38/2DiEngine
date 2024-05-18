#ifndef TIMER_H
#define TIMER_H

constexpr int FPS = 60;
constexpr float DELTA_TIME = 1.5f;

class Timer
{
public:
	void GetTick();
	inline float GetDeltaTime() { return m_DeltaTime; }
	inline static Timer* GetInstance() {
		return s_Instance = (s_Instance != nullptr) ? s_Instance : new Timer();
	}
private:
	Timer();
	static Timer* s_Instance;
	float m_DeltaTime;
	float m_LastTime;
};

#endif // !TIMER_H

