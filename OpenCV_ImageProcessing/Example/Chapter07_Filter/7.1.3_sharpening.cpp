#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void filter(Mat img, Mat& dst, Mat mask)
{
	dst = Mat(img.size(), CV_32F, Scalar(0));			//회선 결과 저장 행렬
	Point h_m = mask.size() / 2;						//마스크 중심좌표

	for (int i = h_m.x; i < img.rows - h_m.y; i++)
	{
		for (int j = h_m.x; j < img.cols - h_m.x; j++)
		{
			float sum = 0;
			for (int u = 0; u < mask.rows; u++)
			{
				for (int v = 0; v < mask.cols; v++)
				{
					int y = i + u - h_m.y;
					int x = j + v - h_m.x;
					sum += mask.at<float>(u, v) * img.at<uchar>(y, x);
				}
			}
			dst.at<float>(i, j) = sum;
		}
	}
}

int main(void)
{
	Mat image = imread("H:/2021년 4학년 1학기/영상처리/7장이미지/filter_blur.jpg", 0);
	CV_Assert(image.data);

	float data1[] = {
		0, -1, 0
		- 1, 5, -1,
		0, 1, 0 
	};
	float data2[] = {
		-1, -1, -1,
		-1, 9, -1,
		-1, -1, -1
	};
	Mat mask1(3, 3, CV_32F, data1);
	Mat mask2(3, 3, CV_32F, data2);
	Mat sharpen1, sharpen2;
	filter(image, sharpen1, mask1);
	filter(image, sharpen2, mask2);
	sharpen1.convertTo(sharpen1, CV_8U);
	sharpen2.convertTo(sharpen2, CV_8U);

	imshow("image", image);
	imshow("sharpen1", sharpen1);
	imshow("sharpen2", sharpen2);
	waitKey();
	return 0;
}