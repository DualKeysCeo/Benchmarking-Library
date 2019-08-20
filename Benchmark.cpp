#include <string>
#include <stdio.h>
#include <Windows.h>

#include "Benchmark.h"

namespace benchmark {
	Timer::Timer() {
		m_StartTimepoint = std::chrono::high_resolution_clock::now();
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

		if (ms > 1000) {
			printf("Timer response: %.3f ms (%.3f s)\n", ms, s);
			return;
		}
		printf("Timer response: %lld us (%.3f ms)\n", us, ms);
	}
}