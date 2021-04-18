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

	Mat w_0(3, 3, CV_32F, Scalar(0));
	for (int i = 0; i < 3; i++)
	{
		w_0.at<float>(i, i) = w.at<float>(i, 0);
	}
	cout << "w_0" << endl << w_0 << endl << endl;

	Mat u_1(3, 2, CV_32F, Scalar(0)), w_1(2, 2, CV_32F, Scalar(0)), vt_1(2, 4, CV_32F, Scalar(0));

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			u_1.at<float>(i, j) = u.at<float>(i, j);
		}
	}
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			w_1.at<float>(i, j) = w_0.at<float>(i, j);
		}
	}
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			vt_1.at<float>(i, j) = vt.at<float>(i, j);
		}
	}
	cout << "u_1" << endl << u_1 << endl << endl;
	cout << "w_1" << endl << w_1 << endl << endl;
	cout << "vt_1" << endl << vt_1 << endl << endl;
	cout << "u_1 * w_1 * vt_1" << endl << u_1 * w_1 * vt_1 << endl << endl;

	Mat result;
	result = u * w_0 * vt;
	cout << "result" << endl << result << endl << endl;

	return 0;
}