#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>

using namespace cv;
using namespace std;

int main(void)
{
	Mat score = imread("H:/2021�� 4�г� 1�б�/����ó��/4���̹���/score.jpg", 0);
	Rect roi(10, 10, 3, 3);

	cout << "score = " << endl << score.row(100) << endl;
	return 0;
}
