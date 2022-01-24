#pragma once

#include <opencv2/core/core.hpp>

class IDetector
{
public:
	virtual void update(cv::Mat &fieldImage) = 0;
};