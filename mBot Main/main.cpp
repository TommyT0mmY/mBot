#include <iostream>
#include <chrono>

#include "..\mBot Backend\mBot Backend.h"
#include "..\mBot Temp Frontend\mBot Temp Frontend.h"
#include "..\mBot Backend\libs\video-feed\VideoFeed.h"

int main() {
	std::cout << "hello world\n";

	//utilizzare 0 per la webca mdi default o usare un una stringa con un path per usare i file(non è ancora testato bene potrebbe dare problemi)
	VideoFeed videoFeed(0);

	Backend backend(videoFeed);
	Frontend frontend;
	

	auto start = std::chrono::high_resolution_clock::now();
	auto end = std::chrono::high_resolution_clock::now();

	float targetFrameRate = 50;

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