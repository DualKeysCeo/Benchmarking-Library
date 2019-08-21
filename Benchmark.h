#pragma once
#include <chrono>
#include <vector>
#include <fstream>
#include <Windows.h>

namespace benchmark {
	class Timer {
	public:
		Timer();
		Timer(char const* filePath);
		~Timer();
		void Stop();
	private:
		std::ofstream m_LogFile;
		std::chrono::time_point <std::chrono::high_resolution_clock > m_StartTimepoint;
	};
}