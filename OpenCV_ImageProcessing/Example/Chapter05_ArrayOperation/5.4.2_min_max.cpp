#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(void)
{
	uchar data[] = {
		10, 200, 5, 7, 9,
		15, 35, 60, 80, 170,
		100, 2, 55, 37, 70
	};
	Mat m1(3, 5, CV_8U, data);
	Mat m2(3, 5, CV_8U, Scalar(50));
	Mat m_min, m_max;
	double minVal, maxVal;
	int minIdx[2] = {}, maxIdx[2] = {};
	Point minLoc, maxLoc;

	min(m1, 30, m_min);
	max(m1, m2, m_max);
	minMaxIdx(m1, &minVal, &maxVal, minIdx, maxIdx);
	minMaxLoc(m1, 0, 0, &minLoc, &maxLoc);

	cout << "[m1] = " << endl << m1 << endl << endl;
	cout << "[m_min] = " << endl << m_min << endl;
	cout << "[m_max] = " << endl << m_max << endl << endl;

	cout << "m1 Çà·Ä ¿ø¼Ò ÃÖ¼Ú°ª" << minVal << endl;
	cout << "ÃÖ´ë°ª ÁÂÇ¥ : " << maxIdx[1] << ", " << maxIdx[0] << endl << endl;

	cout << "m1 Çà·Ä ÃÖ¼Ú°ª ÁÂÇ¥ : " << minLoc << endl;
	cout << "m1 Çà·Ä ÃÖ´ñ°ª ÁÂÇ¥ : " << maxLoc << endl;
	return 0;
}