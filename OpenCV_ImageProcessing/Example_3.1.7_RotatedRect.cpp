#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(void)
{
	Mat image(300, 500, CV_8UC1, Scalar(255));	//행렬 선언
	Point2f center(250, 150), pts[4];					//image 매트릭스 변수의 제일 중앙점
	Size2f size(300, 100);
	RotatedRect rot_rect(center, size, 20);			//회전사각형 선언

	Rect bound_rect = rot_rect.boundingRect();
	rectangle(image, bound_rect, Scalar(0), 1);	//사각형 그리기(배열판(Mat), 그릴 사각형, 농도, 선 굵기)
	circle(image, rot_rect.center, 2, Scalar(0), 2);	//원 그리기(배열판(Mat), 점좌표, 반지름크기, 농도, 선 굵기)
	rot_rect.points(pts);
	//rectangle(image, rot_rect, Scalar(0), 1);
	//for문을 사용하는 이유는 rectangle에 (Mat, RotatedRect, Scalar, int) 에 해당하는 오버로드가 없거든.-> 직접 선 그어야함
	for (int i = 0; i < 4; i++)
	{
		circle(image, pts[i], 4, Scalar(0), 1);					//회전한 사각형의 꼭짓점 표시기능
		line(image, pts[i], pts[(i + 1) % 4], Scalar(0), 2);	//라인그리기(배열판(Mat), 점좌표1, 점좌표2, 농도, 선 굵기)
		//나머지 연산을 통해 점 2개씩 집어서 이어줌
	}
	
	imshow("회전사각형", image); //출력창 이름 및 출력
	waitKey(0);
	return 0;
}