#include "Timer.h"

InstrumentationTimer::InstrumentationTimer(const char* name)
	:m_Name(name), m_Stopped(false)
{
	m_StartTimePoint = std::chrono::high_resolution_clock::now();
}

void InstrumentationTimer::Stop()
{
	auto endTimePoint = std::chrono::high_resolution_clock::now();
	long long start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimePoint).time_since_epoch().count();
	long long end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimePoint).time_since_epoch().count();
	Instrumentor::Get().WriteProfile({ m_Name,start,end });
	//std::cout << "\n" << m_Name << ": " << (end - start);
	m_Stopped = true;

}

InstrumentationTimer::~InstrumentationTimer()
{
	if (!m_Stopped)
	{
		Stop();
	}
}