#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>

using namespace cv;
using namespace std;

int main(void)
{
	Mat score = imread("H:/2021년 4학년 1학기/영상처리/4장이미지/score.jpg", 0);
	Mat write_exec = imread("H:/2021년 4학년 1학기/영상처리/4장이미지/write_exec1.jpg", 0);
	CV_Assert(score.data && write_exec.data);
	Mat_<float> score_32f, write_exec_32f;
	//score.convertTo(score_32f, CV_32F, 1 / 255.0f, 0.0f);	//32F로 바뀌었으므로 range : 0~1 정수값을 255로 나누어야 한다.
	write_exec.convertTo(write_exec_32f, CV_32F, 1 / 255.0f, 0.0f);

	//Mat_<float> score_u, score_w, score_vt;
	Mat_<float> write_u, write_w, write_vt;

	//SVDecomp(score_32f, score_w, score_u, score_vt);
	SVDecomp(write_exec_32f, write_w, write_u, write_vt);

	/*
	cout << "score_32f = " << endl << score_32f.row(100) << endl;
	cout << "score_w = " << endl << score_w << endl;
	cout << "score_u = " << endl << score_u.row(100) << endl;
	cout << "score_vt = " << endl << score_vt.row(100) << endl;
	cout << "write_exec_32f = " << endl << write_exec.row(100) << endl;
	cout << "write_w = " << endl << write_w << endl;
	cout << "write_u = " << endl << write_u.row(100) << endl;
	cout << "write_vt = " << endl << write_vt.row(100) << endl;
	*/

	/*
	imshow("score_u", score_u);
	imshow("score_w", score_w);
	imshow("score_vt", score_vt);
	imshow("score", score_32f);
	imshow("write_u", write_u);
	imshow("write_w", write_w);
	imshow("write_vt", write_vt);
	imshow("write_exec", write_exec);
	*/

	cout << "write_u size = " << write_u.size() << endl;
	cout << "write_w size = " << write_w.size() << endl;
	cout << "write_vt size = " << write_vt.size() << endl;
	cout << "write_exec size = " << write_exec_32f.size() << endl;

	waitKey();
	return 0;
}