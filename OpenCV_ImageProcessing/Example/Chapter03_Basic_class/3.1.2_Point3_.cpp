#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(void)
{
	Point3_<int> pt1(100, 200, 300);			//3���� int�� ��ǥ��
	Point3_<float> pt2(92.3f, 125.23f, 250.f);	//3���� float�� ��ǥ��
	Point3f pt3(0.3f, 0.f, 15.7f);					//3���� float�� ��ǥ��
	Point3d pt4(0.25, 0.6, 33.3);					//3���� double�� ��ǥ��

	Point3i pt5 = pt1 - (Point3i)pt2;				//���� ����ȯ(double->int) �� Ŭ���� �� ����
	Point3f pt6 = pt2 * 3.14f;						//Ŭ������ ��� ���� ����
	Point3d pt7 = ((Point3d)pt3 + pt4) * 10.f;	//���� ����ȯ(float->double) �� Ŭ���� �� ����

	//���
	cout << "�� ����(pt4, pt7)�� ���� " << pt4.dot(pt7) << endl;
	cout << "pt5 = " << pt5.x << ", " << pt5.y << ", " << pt5.z << endl;
	cout << "[pt6] = " << pt6 << endl;
	cout << "[pt7] = " << pt7 << endl;
	return 0;
}