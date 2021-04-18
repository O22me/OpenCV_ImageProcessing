#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>

using namespace cv;
using namespace std;

int main(void)
{
	Mat score = imread("H:/2021년 4학년 1학기/영상처리/4장이미지/score.jpg", 0);
	CV_Assert(score.data);

	Mat_<float> score_32f;
	Mat_<float> score_u, score_w, score_vt;
	Mat_<float> result_0, result_mini;

	score.convertTo(score_32f, CV_32F, 1 / 255.0f, 0.0f);

	SVDecomp(score_32f, score_w, score_u, score_vt);

	Mat score_w_0(609, 609, CV_32F, Scalar(0));
	for (int i = 0; i < 609; i++)
	{
		score_w_0.at<float>(i, i) = score_w.at<float>(i, 0);
	}

	float reduce_sigma = 550;
	Mat_<float> score_u_mini(609, (609 - reduce_sigma)), score_w_mini((609 - reduce_sigma), (609 - reduce_sigma)), write_vt_mini((609 - reduce_sigma), 640);
	for (int i = 0; i < 609; i++)
	{
		for (int j = 0; j < (609 - reduce_sigma); j++)
		{
			score_u_mini.at<float>(i, j) = score_u.at<float>(i, j);
		}
	}
	for (int i = 0; i < (609 - reduce_sigma); i++)
	{
		for (int j = 0; j < (609 - reduce_sigma); j++)
		{
			score_w_mini.at<float>(i, j) = score_w_0.at<float>(i, j);
		}
	}
	for (int i = 0; i < (609 - reduce_sigma); i++)
	{
		for (int j = 0; j < 640; j++)
		{
			write_vt_mini.at<float>(i, j) = score_vt.at<float>(i, j);
		}
	}

	result_0 = score_u * score_w_0 * score_vt;
	result_mini = score_u_mini * score_w_mini * write_vt_mini;

	imshow("score", result_0);
	imshow("score_compressed: -550", result_mini);

	waitKey();
	return 0;
}