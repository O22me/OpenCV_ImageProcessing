#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>

using namespace cv;
using namespace std;

int main(void)
{
	double data[] = {
		25, 15, -5,
		15, 18, 0,
		-5, 0, 11
	};

	Mat A = Mat(3, 3, CV_64F, data);

	cout << "A = " << A << endl << endl;

	Cholesky((double*)A.ptr(), A.step, 3, NULL, 0, 0);
	A.at<double>(0, 1) = 0; A.at<double>(0, 2) = 0; A.at<double>(1, 2) = 0;
	cout << "L = " << A << endl << endl;
	cout << "L' = " << A.t() << endl << endl;
	cout << "LL'=" << A * A.t() << endl << endl;

	return 0;
}