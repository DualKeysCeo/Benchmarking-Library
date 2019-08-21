#include <stdio.h>
#include <iostream>

#include "Benchmark.h"

using namespace benchmark;

int main() {
	
	// Test Code
	for (int j = 0; j < 5; ++j) {
		{
			Timer timer("./log.log");

			for (int i = 0; i < 1000; ++i) printf("%i", i);
		}

		{
			Timer timer("./log.log");

			for (int i = 0; i < 1000; i++) printf("%i", i);
		}
	}
	printf("Press enter to finish...");
	return getchar();

}