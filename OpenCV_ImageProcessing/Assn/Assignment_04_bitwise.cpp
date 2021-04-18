#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(void)
{
	Mat coins = imread("H:/2021년 4학년 1학기/영상처리/5장image/coins.jpg", IMREAD_COLOR);
	CV_Assert(coins.data);
	Mat coins32, coins32_exp, another_one;
	coins.convertTo(coins32, CV_32F, 1 / 255.0f);
	exp(coins32, coins32_exp);
	coins32_exp = coins32_exp - coins32.setTo(1);

	Rect roi(10, 10, 3, 3);
	cout << "coins 행렬의 일부" << endl << coins(roi) << endl << endl;
	cout << "coins32 행렬의 일부" << endl << coins32(roi) << endl << endl;
	cout << "coins32_exp 행렬의 일부" << endl << coins32_exp(roi) << endl << endl;

	imshow("coins", coins);
	imshow("coins32", coins32);
	imshow("coins32_exp", coins32_exp);
	waitKey();
	return 0;
}