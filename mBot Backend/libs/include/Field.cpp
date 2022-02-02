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
	
	//riga da eliminare inserita solo per poter compialre
	cv::Mat fieldImage=cv::Mat(100, 100, CV_32FC1,0);


	for (auto detector : detectors) {
		detector->update(fieldImage);
	}
}
