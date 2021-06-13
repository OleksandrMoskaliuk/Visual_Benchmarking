#pragma once
#include "../Src/Source.h"

#ifndef INS_SION
#define INS_SION

struct ProfileResult
{
	std::string Name;
	long long Start, End;
};

struct InstrumentationSession
{
	std::string Name;
};

class Instrumentor
{
private:
	InstrumentationSession* m_CurrentSession;
	std::ofstream  m_OutputStream;
	int m_ProfileCount;
public:
	Instrumentor();
	void BeginSession(const std::string& name, const std::string& filepath = "result.json");
	void EndSession();
	void WriteProfile(const ProfileResult& result);
	void WriteHeader();
	void WriteFooter();
	static Instrumentor& Get();
};


#endif // !INS_SION