#pragma once

#include "Detector.h"
#include "../objects/Player.h"

class PlayerDetector : public IDetector {
private:
	Player player;

public:
	void update(cv::Mat& image);
	Player getPlayer();
};