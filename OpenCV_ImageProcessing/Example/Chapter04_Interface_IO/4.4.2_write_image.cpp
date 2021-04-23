#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(void)
{
	Mat img8 = imread("H:/2021�� 4�г� 1�б�/����ó��/4���̹���/ex_color.jpg", IMREAD_COLOR);
	CV_Assert(img8.data); //Assert : data�ε忡 �����ߴٸ� Exception�߻� 

	vector<int> params_jpg, params_png;
	params_jpg.push_back(IMWRITE_JPEG_QUALITY);
	params_jpg.push_back(50);
	params_png.push_back(IMWRITE_PNG_COMPRESSION);
	params_png.push_back(9);

	imwrite("H:/2021�� 4�г� 1�б�/����ó��/4���̹���/write_test1.jpg", img8);
	imwrite("H:/2021�� 4�г� 1�б�/����ó��/4���̹���/write_test2.jpg", img8, params_jpg);
	imwrite("H:/2021�� 4�г� 1�б�/����ó��/4���̹���/write_test3.png", img8, params_png);
	imwrite("H:/2021�� 4�г� 1�б�/����ó��/4���̹���/write_test4.bmp", img8);
	return 0;
}