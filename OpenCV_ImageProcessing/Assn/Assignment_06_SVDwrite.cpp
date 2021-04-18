#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>

using namespace cv;
using namespace std;

int main(void)
{
	Mat write_exec = imread("H:/2021년 4학년 1학기/영상처리/4장이미지/write_exec1.jpg", 0);
	CV_Assert(write_exec.data);

	Mat_<float> write_exec_32f;
	Mat_<float> write_u, write_w, write_vt;
	Mat_<float> result_0, result_mini;

	write_exec.convertTo(write_exec_32f, CV_32F, 1 / 255.0f, 0.0f);

	SVDecomp(write_exec_32f, write_w, write_u, write_vt);

	Mat write_w_0(360, 360, CV_32F, Scalar(0));
	for (int i = 0; i < 360; i++)
	{
		write_w_0.at<float>(i, i) = write_w.at<float>(i, 0);
	}

	float reduce_sigma = 300;
	Mat_<float> write_u_mini(360, (360 - reduce_sigma)), write_w_mini((360 - reduce_sigma), (360 - reduce_sigma)), write_vt_mini((360 - reduce_sigma), 480);
	for (int i = 0; i < 360; i++)
	{
		for (int j = 0; j < (360 - reduce_sigma); j++)
		{
			write_u_mini.at<float>(i, j) = write_u.at<float>(i, j);
		}
	}
	for (int i = 0; i < (360 - reduce_sigma); i++)
	{
		for (int j = 0; j < (360 - reduce_sigma); j++)
		{
			write_w_mini.at<float>(i, j) = write_w_0.at<float>(i, j);
		}
	}
	for (int i = 0; i < (360 - reduce_sigma); i++)
	{
		for (int j = 0; j < 480; j++)
		{
			write_vt_mini.at<float>(i, j) = write_vt.at<float>(i, j);
		}
	}

	result_0 = write_u * write_w_0 * write_vt;
	result_mini = write_u_mini * write_w_mini * write_vt_mini;

	imshow("write_exec", result_0);
	imshow("write_exec_compressed: -300", result_mini);

	waitKey();
	return 0;
}