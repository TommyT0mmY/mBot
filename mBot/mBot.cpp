#include <opencv2\cvconfig.h>
#include <opencv2\highgui\highgui.hpp>
#include <iostream>

#define CAM_NUMBER 2

int main()
{

	//apertura camera
	cv::VideoCapture cap(CAM_NUMBER);
	if (!cap.isOpened()) {
		std::cout << "Opening cam Error! change CAM_NUMBER";
		return -1;
	}

	//frame showing
	while (1) {
		cv::Mat frame;
		cap.read(frame);
		imshow("camera", frame);
		if (cv::waitKey(30) == 27) {
			cap.release();//clears the camera buffer
			return 0; //esc
		}
	}


}

