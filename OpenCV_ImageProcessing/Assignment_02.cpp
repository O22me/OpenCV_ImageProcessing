#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(void)
{
	Mat image(300, 500, CV_8UC1, Scalar(255));	
	Point2f center(250, 150), pts[4];					//중심점 설정
	Size2f size(300, 100);
	RotatedRect rot_rect(center, size, 0);

	//rot_rect.angle = 0; 인 경우
	for (int i = 0; i < 4; i++)
	{
		rot_rect.points(pts);
		circle(image, pts[i], 4, Scalar(0), 1);
		line(image, pts[i], pts[(i + 1) % 4], Scalar(200), 2);
	}
	rot_rect.angle = 90;
	for (int i = 0; i < 4; i++)
	{
		rot_rect.points(pts);
		circle(image, pts[i], 4, Scalar(0), 1);
		line(image, pts[i], pts[(i + 1) % 4], Scalar(200), 2);
	}
	rot_rect.angle = 180;
	for (int i = 0; i < 4; i++)
	{
		rot_rect.points(pts);
		circle(image, pts[i], 4, Scalar(0), 1);
		line(image, pts[i], pts[(i + 1) % 4], Scalar(200), 2);
	}
	rot_rect.angle = 270;
	for (int i = 0; i < 4; i++)
	{
		rot_rect.points(pts);
		circle(image, pts[i], 4, Scalar(0), 1);
		line(image, pts[i], pts[(i + 1) % 4], Scalar(200), 2);
	}
	rot_rect.angle = -90;
	for (int i = 0; i < 4; i++)
	{
		rot_rect.points(pts);
		circle(image, pts[i], 4, Scalar(0), 1);
		line(image, pts[i], pts[(i + 1) % 4], Scalar(200), 2);
	}
	rot_rect.angle = -180;
	for (int i = 0; i < 4; i++)
	{
		rot_rect.points(pts);
		circle(image, pts[i], 4, Scalar(0), 1);
		line(image, pts[i], pts[(i + 1) % 4], Scalar(200), 2);
	}

	imshow("회전회오리", image); //출력창
	waitKey(0);
	return 0;
}