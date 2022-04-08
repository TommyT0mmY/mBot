#pragma once

#include "Detector.h"
#include "../objects/Field.h"
#include <opencv2/core/core.hpp>
#include <vector>
#include <string>


class FieldDetector : public IDetector {
private:
	Field field;

	//Vettori utilizzati da update per detectare i QR Code
	std::vector<std::string> updateDecodeInfo;
	std::vector<cv::Point> updateCorners;

public:
	void update(cv::Mat& image);

	Field getField();

	FieldDetector();
	~FieldDetector();
};
