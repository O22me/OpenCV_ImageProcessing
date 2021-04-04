#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(void)
{
	Mat image = imread("D:/2021�� 4�г� 1�б�/����ó��/5��image/ex_color.jpg");
	CV_Assert(image.data);

	Mat x_axis, y_axis, xy_axis, rep_img, trans_img;
	flip(image, x_axis, 0);		//x�� ���� ���ϵ����� : int flipcode = 0
	flip(image, y_axis, 1);		//y�� ���� ���ϵ����� : int flipcode = 1
	flip(image, xy_axis, -1);		//xy�� ���� ���ϵ����� : int flipcode = -1

	repeat(image, 1, 2, rep_img); //y�� �ݺ�, x�� �ݺ� ����
	transpose(image, trans_img);

	imshow("image", image);
	imshow("y_axis", y_axis);
	imshow("rep_img", rep_img);
	waitKey();
	return 0;
}