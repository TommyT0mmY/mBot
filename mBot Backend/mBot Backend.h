#pragma once
#include "libs/video-feed/VideoFeed.h"

struct DataTransfer {
	//cv::Mat* image;
};

class Backend {
public:
	Backend();

	DataTransfer update();
	VideoFeed videoFeed = VideoFeed("C:/Users/studente\\source\\repos\\mBot/Immagini/CampoCalcio1300x800_A1.jpg");
private:
};