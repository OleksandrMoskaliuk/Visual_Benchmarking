#pragma once
#include "..\Src\Source.h"

#ifndef INST_TIMER
#define INST_TIMER

class InstrumentationTimer
{
public:
	InstrumentationTimer(const char* name);
	void Stop();
	~InstrumentationTimer();
private:
	std::chrono::time_point<std::chrono::steady_clock> m_StartTimePoint;
	const char* m_Name;
	bool m_Stopped;
};

#endif // !INST_TIMER
