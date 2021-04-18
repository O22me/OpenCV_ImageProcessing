#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(void)
{
    Mat ex_color = imread("H:/2021년 4학년 1학기/영상처리/5장image/ex_color.jpg", 0);
    Mat coins = imread("H:/2021년 4학년 1학기/영상처리/5장image/coins.jpg", 0);
    CV_Assert(ex_color.data && coins.data);
    Mat ex_color_out, coins_out;

    convertScaleAbs(ex_color, ex_color_out, 2.0, 0);
    convertScaleAbs(coins, coins_out, 2.0, 0);

    Rect roi(10, 10, 3, 3);
    cout << "score = " << ex_color(roi) << endl;
    cout << "score_out = " << ex_color_out(roi) << endl;
    cout << "logo = " << coins(roi) << endl;
    cout << "logo_out = " << coins_out(roi) << endl;

    imshow("score", ex_color);
    imshow("score_out", ex_color_out);
    imshow("logo", coins);
    imshow("logo_out", coins_out);

    waitKey();
	return 0;
}