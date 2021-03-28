#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void print_matInfo(string name, Mat m)
{
	string mat_type;	//자료형 저장 문자열 클래스
	if (m.depth() == CV_8U)			mat_type = "CV_8U";
	else if (m.depth() == CV_8S)		mat_type = "CV_8S";
	else if (m.depth() == CV_16U)	mat_type = "CV_16U";
	else if (m.depth() == CV_16S)	mat_type = "CV_16S";
	else if (m.depth() == CV_32S)	mat_type = "CV_32S";	//int형
	else if (m.depth() == CV_32F)	mat_type = "CV_32F";
	else if (m.depth() == CV_64F)	mat_type = "CV_64F";	//double형

	cout << name << " 크기" << m.size() << ", ";							//크기 표시 [X(열) × Y(행)] //반대로 표시되니 참고할 것.
	cout << " 자료형" << mat_type << "C" << m.channels() << endl;	//자료형과 채널표시
	cout << m << endl << endl;												//행렬 표시
}

int main(void)
{
	Mat m1, m2, m3, m4(2, 6, CV_8UC1);			//2×6 행렬, 8비트-unsigned-1채널
	Mat add1(2, 3, CV_8UC1, Scalar(100));			//2×3 행렬, 8비트-unsigned-1채널, 모두 100으로 초기화
	Mat add2 = (Mat)Mat::eye(4, 3, CV_8UC1);	//4×3 단위행렬, 8비트-unsigned-1채널

	m1.push_back(100), m1.push_back(200);
	m2.push_back(100.5), m2.push_back(200.6);

	m3.push_back(add1);
	m4.push_back(add2);

	//m4.push_back(add1);								//열 개수 불일치로 에러발생
	//m4.push_back(100);								//CV_8UC1 != CV_32SC1 자료형 불일치로 에러발생
	m4.push_back(add1.reshape(1, 1));
	m4.push_back(add2.reshape(1, 2));

	print_matInfo("m1", m1), print_matInfo("m2", m2);
	print_matInfo("m3", m3), print_matInfo("m4", m4);

	m1.pop_back(1);
	m2.pop_back(2);
	m3.pop_back(3);
	cout << "m1" << endl << m1 << endl;
	cout << "m2" << endl << m2 << endl;
	cout << "m3" << endl << m3 << endl;
	return 0;
}