#pragma once

#include "Detector.h"
#include "../objects/Ball.h"

class BallDetector : public IDetector {
private:
	Ball ball;

public:
	void update(cv::Mat& normalizedFieldImage);


	Ball getBall();
};