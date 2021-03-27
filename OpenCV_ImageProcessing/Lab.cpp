#include <opencv2\opencv.hpp>

using namespace cv;
using namespace std;

int main() {

	for (int deg = 3600; deg > 0; deg += 1) { //�����ʿ� process����ȭ
		Mat image(700, 700, CV_8UC1, Scalar(255));
		Point2f center(250, 200), pts[4];
		Size2f size(300, 100);
		RotatedRect rot_rect(center, size, deg); // constant is angle

		Rect bound_rect = rot_rect.boundingRect();
		rectangle(image, bound_rect, Scalar(0), 1);
		circle(image, rot_rect.center, 1, Scalar(0), 2);
		rot_rect.points(pts);
		for (int i = 0; i < 4; i++) {
			circle(image, pts[i], 14, Scalar(0), 1); // ������ ����, ����° �Ű������� ���� ũ��
			line(image, pts[i], pts[(i + 1) % 4], Scalar(0), 2); // ���� ����, �ټ���° �Ű������� ������ �β�
		}

		imshow("ȸ���簢��", image);
		waitKey(10);
	}

	return 0;

}