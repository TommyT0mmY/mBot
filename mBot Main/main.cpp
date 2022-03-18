#include <iostream>
#include <chrono>

#include "..\mBot Backend\mBot Backend.h"
#include "..\mBot Temp Frontend\mBot Temp Frontend.h"

int main() {
	std::cout << "hello world\n";

	Backend backend;
	Frontend frontend;
	

	auto start = std::chrono::high_resolution_clock::now();
	auto end = std::chrono::high_resolution_clock::now();

	float targetFrameRate = 30;

	std::chrono::nanoseconds counter(0);
	std::chrono::nanoseconds nanosecondsPerFrame((int)(1.f / (float)targetFrameRate * 1e9));

	while (true) {
		start = std::chrono::high_resolution_clock::now();

		if (counter >= nanosecondsPerFrame) {
			counter = std::chrono::nanoseconds(0);

			DataTransfer data = backend.update();
			frontend.update(data);
		}

		end = std::chrono::high_resolution_clock::now();

		counter += end - start;
	}

	std::cout << "end\n";
}