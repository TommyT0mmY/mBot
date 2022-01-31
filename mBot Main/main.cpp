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

	std::chrono::nanoseconds Counter(0);
	std::chrono::nanoseconds NanosecondsPerFrame((int)(1.f / (float)targetFrameRate * 1e9));

	while (1) {
		start = std::chrono::high_resolution_clock::now();

		if (Counter >= NanosecondsPerFrame) {
			Counter = std::chrono::nanoseconds(0);

			DataTransfer data = backend.update();
			frontend.update(data);
		}

		end = std::chrono::high_resolution_clock::now();

		Counter += end - start;
	}

	std::cout << "end\n";
}
