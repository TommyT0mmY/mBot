#include "Field.h"

void Field::addDetector(IDetector* detector)
{
	detectors.push_back(detector);
}

void Field::update()
{

	// TODO call normalize field etc.

	for (auto dect : detectors) {
		dect->update(fieldImage);
	}
}
