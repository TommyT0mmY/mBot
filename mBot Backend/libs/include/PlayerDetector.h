#pragma once

#include "Detector.h"

class PlayerDetector : IDetector {
public:
	void update(cv::Mat& fieldImage);
};