#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(void)
{
	double data[] = {
		1, 2, 4,
		3, 8, 14,
		2, 6, 13
	};

	Mat A = Mat(3, 3, CV_64F, data);

	LU((double*)A.ptr(), A.step, 3, NULL, 0, 0);
	A.at<double>(0, 1) = 0; A.at<double>(0, 2) = 0; A.at<double>(1, 2) = 0;
	cout << "L = " << A << endl;
	cout << "L' = " << A.t() << endl;
	cout << "LL'=" << A * A.t() << endl;

	return 0;
}