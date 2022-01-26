#include <iostream>
#include "..\mBot Backend\mBot Backend.h"
#include "..\mBot Temp FrontEnd\mBot Temp Frontend.h"

int main() {

	std::cout << "hello world\n";

	Backend backend;
	backend = Backend();

	Frontend frontend;
	frontend = Frontend();

	//while (1) {
	DataTransfer data = backend.update();
	frontend.update(data);

	std::cout << "end\n";
}