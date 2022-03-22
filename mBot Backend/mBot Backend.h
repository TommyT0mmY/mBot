#pragma once
#include "libs/video-feed/VideoFeed.h"
#include "libs/ImageNormalizer.h"
#include "libs/detectors/FieldDetector.h"
#include "libs/detectors/BallDetector.h"
#include "libs/detectors/PlayerDetector.h"

struct DataTransfer {
	//cv::Mat* image;
};

class Backend {
public:
	Backend(VideoFeed _videoFeed);

	DataTransfer update();
	VideoFeed videoFeed;
	ImageNormalizer imageNormalizer;

	FieldDetector fieldDetector;
	BallDetector ballDetector;
	PlayerDetector playerDetector;
private:
};