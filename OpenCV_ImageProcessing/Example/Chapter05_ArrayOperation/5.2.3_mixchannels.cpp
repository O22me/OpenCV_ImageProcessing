#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(void)
{
	Mat ch0(3, 4, CV_8U, Scalar(10));	//단일채널생성
	Mat ch1(3, 4, CV_8U, Scalar(20));
	Mat ch2(3, 4, CV_8U, Scalar(30));
	Mat ch_012;

	vector<Mat> vec_012;				//행렬원소를 갖는 벡터
	vec_012.push_back(ch0);				//벡터에 단일채널 행렬 추가
	vec_012.push_back(ch1);
	vec_012.push_back(ch2);
	merge(vec_012, ch_012);				//행렬 벡터로 다중 채널 행렬 합성

	Mat ch_13(ch_012.size(), CV_8UC2);
	Mat ch_2(ch_012.size(), CV_8UC1);
	Mat out[] = { ch_13, ch_2 };
	int from_to[] = { 0, 0, 2, 1, 1, 2 };					//입력 출력
	mixChannels(&ch_012, 1, out, 2, from_to, 3);	//채널 합성

	cout << "[ch_123] = " << endl << ch_012 << endl << endl;
	cout << "[ch_13] = " << endl << ch_13 << endl;
	cout << "[ch_2] = " << endl << ch_2 << endl;
	return 0;
}