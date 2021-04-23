#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(void)
{
	Mat image = imread("H:/2021년 4학년 1학기/영상처리/5장image/ex_color.jpg", IMREAD_COLOR);
	CV_Assert(image.data);

	Mat bgr[3];
	split(image, bgr);

	imshow("image", image);
	imshow("blue 채널", bgr[0]);
	imshow("green 채널", bgr[1]);
	imshow("red 채널", bgr[2]);
	waitKey();
	return 0;
}