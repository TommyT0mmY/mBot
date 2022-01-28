// mBot Backend.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include "mBot Backend.h"

#include <iostream>

Backend::Backend() {
	std::cout << "backend constructor call\n";
}

DataTransfer Backend::update() {
	std::cout << "backend update call\n";

	DataTransfer result;


	return result;
}
