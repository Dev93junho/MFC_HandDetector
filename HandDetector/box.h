#pragma once
#include "opencv2/opencv.hpp"

using namespace cv;

int main(){
	// created Mat object for save image
	int width=640;
	int height=480;

	Mat img(height, width, CV_8UC3, Scalar(0, 0, 0));

	// box coordination top-left ==>(50,50) , below-right ==> (450,450)
	// line 3, red

	rectangle(img, Point(50, 50), Point(450, 450), Scalar(0, 0, 225), 3);

	// box left-top ==> (150, 200), below-right ==> (250, 300)

	rectangle(img, Point(150, 200), Point(250, 300), Scalar(255, 0, 255), -1);

	return 0;
}