#pragma once
#include <chrono>
#include <vector>
#include <fstream>
#include <Windows.h>

namespace benchmark {
	class Timer {
	public:
		Timer(const char* timerName);
		Timer(const char* timerName, char const* logPath);
		~Timer();
		void Stop();
	private:
		const char* m_TimerName;
		std::ofstream m_LogFile;
		std::chrono::time_point <std::chrono::high_resolution_clock > m_StartTimepoint;
	};
}