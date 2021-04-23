#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void differOp(Mat img, Mat& dst, int mask_size)
{
	dst = Mat(img.size(), CV_8U, Scalar(0));
	Point h_m(mask_size / 2, mask_size / 2);
	int mask_length = mask_size * mask_size;

	for(int i = h_m; i < img.rows)
}