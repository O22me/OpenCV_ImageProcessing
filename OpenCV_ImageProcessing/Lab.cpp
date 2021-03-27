#include <opencv2\opencv.hpp>

using namespace cv;
using namespace std;

int main() {

	for (int deg = 3600; deg > 0; deg += 1) { //수정필요 process과부화
		Mat image(700, 700, CV_8UC1, Scalar(255));
		Point2f center(250, 200), pts[4];
		Size2f size(300, 100);
		RotatedRect rot_rect(center, size, deg); // constant is angle

		Rect bound_rect = rot_rect.boundingRect();
		rectangle(image, bound_rect, Scalar(0), 1);
		circle(image, rot_rect.center, 1, Scalar(0), 2);
		rot_rect.points(pts);
		for (int i = 0; i < 4; i++) {
			circle(image, pts[i], 14, Scalar(0), 1); // 꼭지점 생성, 세번째 매개변수는 원의 크기
			line(image, pts[i], pts[(i + 1) % 4], Scalar(0), 2); // 라인 생성, 다섯번째 매개변수는 라인의 두께
		}

		imshow("회전사각형", image);
		waitKey(10);
	}

	return 0;

}