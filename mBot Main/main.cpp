#include <iostream>
#include "..\mBot Backend\mBot Backend.h"
#include "..\mBot Temp Frontend\mBot Temp Frontend.h"

int main() {
	std::cout << "hello world\n";

	Backend backend;
	Frontend frontend;

	DataTransfer data = backend.update();
	frontend.update(data);

	std::cout << "end\n";
}