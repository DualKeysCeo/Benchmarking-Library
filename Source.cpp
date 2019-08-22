#include <stdio.h>
#include <iostream>

#include "Benchmark.h"

using namespace benchmark;

int main() {
	Timer overallRuntime("Overall Runtime", "./log.log");
	// Test Code
	for (int j = 0; j < 5; j++) {
		{
			Timer ppi("++i", "./log.log");
			for (int i = 0; i < 1000; ++i) printf("%i", i);
		}

		{
			Timer ipp("i++", "./log.log");
			for (int i = 0; i < 1000; i++) printf("%i", i);
		}
	}

	return 0;

}