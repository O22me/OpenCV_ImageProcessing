#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>

using namespace cv;
using namespace std;

int main(void)
{
	float data[] = {
		3, -1, 2, -3,
		3, -2, 3, 0,
		6, -4, 7, -3
	};
	Mat A = Mat(3, 4, CV_32F, data);
	Mat u, w, vt;
	SVDecomp(A, w, u, vt);
	cout << "A" << endl << A << endl << endl;
	cout << "Sigma" << endl << w << endl << endl;
	cout << "U matrix" << endl << u << endl << endl;
	cout << "V transpose" << endl << vt << endl << endl;

	return 0;
}