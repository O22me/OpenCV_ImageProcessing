#include <opencv2/opencv.hpp>

using namespace std;

int main(void)
{
	cv::Point_<int> pt1(100, 200);				//int형 좌표값
	cv::Point_<float> pt2(92.3f, 125.23f);		//float형 좌표값
	cv::Point_<double> pt3(100.2, 300.9);		//double형 좌표값

	cv::Point2i pt4(120, 69);						//2차원 int형 좌표값
	cv::Point2f pt5(0.3f, 0.f), pt6(0.f, 0.4f);		//2차원 float형 좌표값
	cv::Point2d pt7(0.25, 0.6);						//2차원 double형 좌표값

	cv::Point pt8 = pt1 + (cv::Point)pt2;		//Point 클래스 간 +연산자오버로딩
	cv::Point2f pt9 = pt6 * 3.14f;					//Point2f 클래스와 *상수
	cv::Point2d pt10 = (pt3 + (cv::Point2d)pt6) * 10;		//Point2d 로 강제 형변환 후 클래스간 연산

	//출력
	cout << "pt8 = " << pt8.x << ", " << pt8.y << endl;
	cout << "[pt9] = " << pt9 << endl;
	cout << (pt2 == pt6) << endl;
	cout << "pt7과 pt8의 내적 : " << pt7.dot(pt8) << endl;
	return 0;
}