#pragma once

#include <opencv2/core/core.hpp>
#include <opencv2/objdetect.hpp>
#include <vector>
#include <string>
#include "Detector.h"
#include "../objects/Field.h"


class FieldDetector : public IDetector {
private:
	Field field;
	cv::QRCodeDetector qrCodeDetector;

	//Vettori utilizzati da update per detectare i QR Code
	std::vector<std::string> updateDecodeInfo;
	std::vector<cv::Point> updateCorners;

public:
	void update(cv::Mat& image);

	Field getField();

	FieldDetector();
	~FieldDetector();
};
