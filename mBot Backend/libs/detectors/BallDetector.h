#pragma once

#include "Detector.h"
#include "../objects/Ball.h"
#include <opencv2/features2d.hpp>

class BallDetector : public IDetector {
public:
	void update(cv::Mat& image);
	BallDetector();

	
	Ball getBall();
private:
	cv::Ptr<cv::SimpleBlobDetector> detector;

	Ball ball;

	// TODO range
	int lowH = 1;
	int lowS = 59;
	int lowV = 172;

	int highH = 13;
	int highS = 160;
	int highV = 255;
};