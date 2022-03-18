#pragma once

#include "Detector.h"
#include "../objects/Ball.h"

class BallDetector : public IDetector {
public:
	void update(cv::Mat& normalizedFieldImage);

	
	Ball getBall();
private:
	void searchBall();

	Ball ball;

	int lowH;
	int lowS;
	int lowV;

	int highH;
	int highS;
	int highV;
};