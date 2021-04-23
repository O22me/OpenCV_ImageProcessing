#include <opencv2/opencv.hpp>

using namespace std;

int main(void)
{
	cv::Point_<int> pt1(100, 200);				//int�� ��ǥ��
	cv::Point_<float> pt2(92.3f, 125.23f);		//float�� ��ǥ��
	cv::Point_<double> pt3(100.2, 300.9);		//double�� ��ǥ��

	cv::Point2i pt4(120, 69);						//2���� int�� ��ǥ��
	cv::Point2f pt5(0.3f, 0.f), pt6(0.f, 0.4f);		//2���� float�� ��ǥ��
	cv::Point2d pt7(0.25, 0.6);						//2���� double�� ��ǥ��

	cv::Point pt8 = pt1 + (cv::Point)pt2;		//Point Ŭ���� �� +�����ڿ����ε�
	cv::Point2f pt9 = pt6 * 3.14f;					//Point2f Ŭ������ *���
	cv::Point2d pt10 = (pt3 + (cv::Point2d)pt6) * 10;		//Point2d �� ���� ����ȯ �� Ŭ������ ����

	//���
	cout << "pt8 = " << pt8.x << ", " << pt8.y << endl;
	cout << "[pt9] = " << pt9 << endl;
	cout << (pt2 == pt6) << endl;
	cout << "pt7�� pt8�� ���� : " << pt7.dot(pt8) << endl;
	return 0;
}