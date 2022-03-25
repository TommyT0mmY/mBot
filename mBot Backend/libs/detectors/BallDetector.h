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
	void searchBall();

	cv::Ptr<cv::SimpleBlobDetector> detector;

	Ball ball;

	// TODO range
	int lowH = 20;
	int lowS = 80;
	int lowV = 80;

	int highH = 60;
	int highS = 100;
	int highV = 100;
};