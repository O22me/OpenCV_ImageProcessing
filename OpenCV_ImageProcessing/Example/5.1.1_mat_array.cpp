#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(void)
{
	Mat image = imread("D:/2021년 4학년 1학기/영상처리/5장image/ex_color.jpg");
	CV_Assert(image.data);

	Mat x_axis, y_axis, xy_axis, rep_img, trans_img;
	flip(image, x_axis, 0);		//x축 기준 상하뒤집기 : int flipcode = 0
	flip(image, y_axis, 1);		//y축 기준 상하뒤집기 : int flipcode = 1
	flip(image, xy_axis, -1);		//xy축 기준 상하뒤집기 : int flipcode = -1

	repeat(image, 1, 2, rep_img); //y축 반복, x축 반복 순서
	transpose(image, trans_img);

	imshow("image", image);
	imshow("y_axis", y_axis);
	imshow("rep_img", rep_img);
	waitKey();
	return 0;
}