#pragma once

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace cv;
using namespace std;

//TODO
//QRCODE
//trovare i min max corretti
//ball detection
//


int main(int argc, char** argv)
{
	VideoCapture cap(0); //capture the video from web cam

	if (!cap.isOpened())  // if not success, exit program
	{
		cout << "Cannot open the web cam" << endl;
		return -1;
	}

	while (true)
	{
		// immagine della webcam
		Mat imgCapture;

		bool bSuccess = cap.read(imgCapture); // read a new frame from video

		if (!bSuccess) //if not success, break loop
		{
			cout << "Cannot read a frame from video stream" << endl;
			break;
		}
		imshow("Original", imgCapture); //show the original image

		if (waitKey(1) == 27)
		{
			cout << "esc key is pressed by user" << endl;
			break;
		}
	}


	return 0;

}