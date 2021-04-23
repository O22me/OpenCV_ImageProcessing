#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(void)
{
	Mat image = imread("H:/2021�� 4�г� 1�б�/����ó��/5��image/ex_color.jpg", IMREAD_COLOR);
	CV_Assert(image.data);

	Mat bgr[3];
	split(image, bgr);

	imshow("image", image);
	imshow("blue ä��", bgr[0]);
	imshow("green ä��", bgr[1]);
	imshow("red ä��", bgr[2]);
	waitKey();
	return 0;
}