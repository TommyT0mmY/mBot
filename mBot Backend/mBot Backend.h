#pragma once

#include "libs/include/BallDetector.h"
#include "libs/include/PlayerDetector.h"
#include "libs/include/Field.h"

struct DataTransfer {
	//data
};

class Backend {
public:
	Backend();

	DataTransfer update();

};