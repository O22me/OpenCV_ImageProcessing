#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(void)
{
	Mat image(300, 500, CV_8UC1, Scalar(255));	//��� ����
	Point2f center(250, 150), pts[4];					//image ��Ʈ���� ������ ���� �߾���
	Size2f size(300, 100);
	RotatedRect rot_rect(center, size, 20);			//ȸ���簢�� ����

	Rect bound_rect = rot_rect.boundingRect();
	rectangle(image, bound_rect, Scalar(0), 1);	//�簢�� �׸���(�迭��(Mat), �׸� �簢��, ��, �� ����)
	circle(image, rot_rect.center, 2, Scalar(0), 2);	//�� �׸���(�迭��(Mat), ����ǥ, ������ũ��, ��, �� ����)
	rot_rect.points(pts);
	//rectangle(image, rot_rect, Scalar(0), 1);
	//for���� ����ϴ� ������ rectangle�� (Mat, RotatedRect, Scalar, int) �� �ش��ϴ� �����ε尡 ���ŵ�.-> ���� �� �׾����
	for (int i = 0; i < 4; i++)
	{
		circle(image, pts[i], 4, Scalar(0), 1);					//ȸ���� �簢���� ������ ǥ�ñ��
		line(image, pts[i], pts[(i + 1) % 4], Scalar(0), 2);	//���α׸���(�迭��(Mat), ����ǥ1, ����ǥ2, ��, �� ����)
		//������ ������ ���� �� 2���� ��� �̾���
	}
	
	imshow("ȸ���簢��", image); //���â �̸� �� ���
	waitKey(0);
	return 0;
}