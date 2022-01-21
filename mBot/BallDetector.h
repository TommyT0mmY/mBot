#pragma once

#include "Field.h"
#include "Detector.h"

class BallDetector : public IDetector{
public:
	void update(cv::Mat& fieldImage);
};