#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(void)
{
	Mat coins = imread("H:/2021�� 4�г� 1�б�/����ó��/5��image/coins.jpg", IMREAD_COLOR);
	CV_Assert(coins.data);
	Mat coins32, coins32_exp, another_one;
	coins.convertTo(coins32, CV_32F, 1 / 255.0f);
	exp(coins32, coins32_exp);
	coins32_exp = coins32_exp - coins32.setTo(1);

	Rect roi(10, 10, 3, 3);
	cout << "coins ����� �Ϻ�" << endl << coins(roi) << endl << endl;
	cout << "coins32 ����� �Ϻ�" << endl << coins32(roi) << endl << endl;
	cout << "coins32_exp ����� �Ϻ�" << endl << coins32_exp(roi) << endl << endl;

	imshow("coins", coins);
	imshow("coins32", coins32);
	imshow("coins32_exp", coins32_exp);
	waitKey();
	return 0;
}