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

	namedWindow("Control"); //create a window called "Control"

	int iLowH = 0;
	int iHighH = 104;

	int iLowS = 61;
	int iHighS = 191;

	int iLowV = 219;
	int iHighV = 255;

	//Create trackbars in "Control" window
	createTrackbar("LowH", "Control", &iLowH, 179); //Hue (0 - 179)
	createTrackbar("HighH", "Control", &iHighH, 179);

	createTrackbar("LowS", "Control", &iLowS, 255); //Saturation (0 - 255)
	createTrackbar("HighS", "Control", &iHighS, 255);

	createTrackbar("LowV", "Control", &iLowV, 255); //Value (0 - 255)
	createTrackbar("HighV", "Control", &iHighV, 255);


	while (true)
	{
		// immagine della webcam
		Mat imgCapture;

		// matrice per il warp dell'immagine
		Mat matrix;

		// immagine normalizzata
		Mat imgWarp;

		// immagine in formato HSV
		Mat imgHSV;

		// immagine imgHSV con valori booleani se il valore è tra i valori min e max
		Mat imgThresholded;



		bool bSuccess = cap.read(imgCapture); // read a new frame from video

		if (!bSuccess) //if not success, break loop
		{
			cout << "Cannot read a frame from video stream" << endl;
			break;
		}

		//qrcode

		QRCodeDetector detector;

		vector<Point> punti;

		detector.detectMulti(imgCapture, punti);

		for (int i = 0; i < punti.size(); i++) {
			//for (int j = 0; j < punti[i].size(); j++) {
			circle(imgCapture, punti[i], 10, { 255,0,0 });

		}

		//warp
		float w = 250;
		float h = 250;


		//i punti nell'immagine
		Point2f src[4] = { {100,100},{100,200},{300,50},{300,250} };
		//i punti nell'immagine di destinazione comprende altezza e larghezza
		Point2f dst[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };

		matrix = getPerspectiveTransform(src, dst);
		warpPerspective(imgCapture, imgWarp, matrix, Point(w, h));

		imshow("image", imgWarp);

		cvtColor(imgCapture, imgHSV, COLOR_BGR2HSV); //Convert the captured frame from BGR to HSV

		inRange(imgHSV, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), imgThresholded); //Threshold the image

		imshow("Thresholded Image", imgThresholded); //show the thresholded image
		imshow("Original", imgCapture); //show the original image

		if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
		{
			cout << "esc key is pressed by user" << endl;
			break;
		}
	}

	return 0;

}