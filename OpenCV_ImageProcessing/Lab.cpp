#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(void)
{
    float data[] = {
       0, 1, 1,
       1, 1, 2,
       0, 0, 3
    };
    float Qdata[] = {
        0, 1, 0,
        1, 0, 0,
        0, 0, 1
    };
    float Rdata[] = {
        1, 1, 2,
        0, 1, 1,
        0, 0, 3
    };

    //bool checked = solve(Qdata, Rdata, data, DECOMP_QR);

    return 0;
}