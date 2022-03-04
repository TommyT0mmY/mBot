#pragma once

#include <opencv2/core/core.hpp>
#include "Detector.h"
#include "../objects/Field.h"


class FieldDetector : public IDetector {
private:
	Field field;

public:
	void update();

	Field getField();
};
