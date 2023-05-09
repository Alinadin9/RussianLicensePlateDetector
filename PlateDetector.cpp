#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace cv;
using namespace std;



void main() {

	VideoCapture cap(0);
	Mat img;

	CascadeClassifier plateCascade;
	plateCascade.load("Resources/haarcascade_license_plate_rus_16stages.xml");


	if (plateCascade.empty()) { cout << "XML file not loaded" << endl; }

	vector<Rect> plates;

	while (true) {

		cap.read(img);
		plateCascade.detectMultiScale(img, plates, 1.1, 10);

		for (int i = 0; i < plates.size(); i++)
		{
			rectangle(img, plates[i].tl(), plates[i].br(), Scalar(0, 255, 0), 3);
		}

		imshow("image", img);
		waitKey(1);
	}
}
