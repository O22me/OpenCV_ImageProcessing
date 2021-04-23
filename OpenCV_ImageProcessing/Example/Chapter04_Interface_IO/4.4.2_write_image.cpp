#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(void)
{
	Mat img8 = imread("H:/2021년 4학년 1학기/영상처리/4장이미지/ex_color.jpg", IMREAD_COLOR);
	CV_Assert(img8.data); //Assert : data로드에 실패했다면 Exception발생 

	vector<int> params_jpg, params_png;
	params_jpg.push_back(IMWRITE_JPEG_QUALITY);
	params_jpg.push_back(50);
	params_png.push_back(IMWRITE_PNG_COMPRESSION);
	params_png.push_back(9);

	imwrite("H:/2021년 4학년 1학기/영상처리/4장이미지/write_test1.jpg", img8);
	imwrite("H:/2021년 4학년 1학기/영상처리/4장이미지/write_test2.jpg", img8, params_jpg);
	imwrite("H:/2021년 4학년 1학기/영상처리/4장이미지/write_test3.png", img8, params_png);
	imwrite("H:/2021년 4학년 1학기/영상처리/4장이미지/write_test4.bmp", img8);
	return 0;
}