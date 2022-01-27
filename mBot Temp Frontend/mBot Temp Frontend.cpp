// mBot Temp FrontEnd.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include "mBot Temp Frontend.h"

#include <iostream>

Frontend::Frontend() {
	std::cout << "frontend constructor call\n";
}

void Frontend::update(DataTransfer data) {
	std::cout << "frontend update call\n";
}

