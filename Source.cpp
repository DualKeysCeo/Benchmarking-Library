#include "Benchmark.h"
#include <stdio.h>

using namespace benchmark;

int main() {
	
	// Test Code

	{
		Timer timer;

		for (int i = 0; i < 1000; ++i) printf(" ");
	}

	{
		Timer timer;

		for (int i = 0; i < 1000; i++) printf(" ");
	}

}