#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>

using namespace cv;
using namespace std;

int main(void)
{
	Mat score = imread("H:/2021년 4학년 1학기/영상처리/4장이미지/score.jpg", 0);
	Rect roi(10, 10, 3, 3);

	cout << "score = " << endl << score.row(100) << endl;
	return 0;
}
