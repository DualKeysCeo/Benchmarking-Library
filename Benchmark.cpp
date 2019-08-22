#include <string>
#include <stdio.h>
#include <Windows.h>

#include "Benchmark.h"

namespace benchmark {
	Timer::Timer(const char* timerName) {
		m_StartTimepoint = std::chrono::high_resolution_clock::now();
		m_TimerName = timerName;
	}

	Timer::Timer(const char* timerName,
		char const* logPath = "./Benchmark.log"): m_LogFile(logPath, std::ios_base::app) {
		m_StartTimepoint = std::chrono::high_resolution_clock::now();
		m_TimerName = timerName;
	}

	Timer::~Timer() {
		Stop();
	}

	void Timer::Stop() {
		auto endTimepoint = std::chrono::high_resolution_clock::now();
		auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimepoint)
			.time_since_epoch().count();
		auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint)
			.time_since_epoch().count();

		long long us = end - start;
		double ms = us * 0.001;
		double s = ms * 0.001;
		const char* response = "%s response: %lld us (%.3f ms)\n";

		if (ms > 1000) {
			response = "%s response: %.3f ms (%.3f s)\n";
			us = ms;
			ms = s;
		}

		if (m_LogFile.is_open()) {
			char buff[256];
			snprintf(buff, sizeof(buff), response, m_TimerName, us, ms);
			m_LogFile << buff;
			m_LogFile.close();
		}

		printf(response, m_TimerName, us, ms);
	}
}