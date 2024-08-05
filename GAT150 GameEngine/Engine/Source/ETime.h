#pragma once
#include <chrono>

class Time {
private:
	using clock = std::chrono::high_resolution_clock;
public:
	Time() : m_startTime{ clock::now() }, m_frameTime{ clock::now() } {}
	void Tick();
	void reset() { m_startTime = clock::now(); }

	float GetTime() const { return m_time; }
	float GetDeltaTime() const { return m_deltaTime; }

private:
	float m_time = 0.0f;
	float m_deltaTime = 0.0f;

	clock::time_point m_startTime;
	clock::time_point m_frameTime;
};