#pragma once

#include "Field.h"

void Field::addDetector(IDetector* detector) {
	detectors.push_back(detector);
}

void Field::initFieldNormalization() {

}

void Field::normalizeField() {

}

void Field::update() {
	Field::normalizeField();

	for (auto detector : detectors) {
		detector->update(fieldImage);
	}
}
