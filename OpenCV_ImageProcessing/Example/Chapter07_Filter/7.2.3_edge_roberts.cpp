#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void filter(Mat img, Mat& dst, Mat mask)
{
	dst = Mat(img.size(), CV_32F, Scalar(0));			//ȸ�� ��� ���� ���
	Point h_m = mask.size() / 2;						//����ũ �߽���ǥ

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
void differential(Mat image, Mat& dst, float data1[], float data2[])
{
	Mat dst1, dst2;
	Mat mask1(3, 3, CV_32F, data1);
	Mat mask2(3, 3, CV_32F, data2);

	filter(image, dst1, mask1);
	filter(image, dst2, mask2);
	magnitude(dst1, dst2, dst);

	dst1 = abs(dst1);
	dst2 = abs(dst2);
	dst.convertTo(dst, CV_8U);
	dst1.convertTo(dst1, CV_8U);
	dst2.convertTo(dst2, CV_8U);
	imshow("dst1", dst1);
	imshow("dst2", dst2);
}

int main(void)
{
	Mat image = imread("H:/2021�� 4�г� 1�б�/����ó��/7���̹���/filter_blur.jpg", 0);
	CV_Assert(image.data);

	float data1[] = {
		-1, 0, 0,
		0, 1, 0,
		0, 0, 0
	};
	float data2[] = {
		0, 0, -1,
		0, 1, 0,
		0, 0, 0
	};

	Mat dst;
	differential(image, dst, data1, data2);

	imshow("image", image);
	imshow("�ι��� ����", dst);
	waitKey();
	return 0;
}