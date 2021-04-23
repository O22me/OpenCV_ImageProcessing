#include <iostream>

#define MAX_MAT_SIZE 10
#define SIZE_OF_SQUARE 3
using namespace std;

void LUdecomp(float InputArray[MAX_MAT_SIZE][MAX_MAT_SIZE], float OutputArray_L[MAX_MAT_SIZE][MAX_MAT_SIZE], float OutputArray_U[MAX_MAT_SIZE][MAX_MAT_SIZE], int n);

int main(void)
{
    float input[MAX_MAT_SIZE][MAX_MAT_SIZE], lower[MAX_MAT_SIZE][MAX_MAT_SIZE], upper[MAX_MAT_SIZE][MAX_MAT_SIZE];
    int n;
    cout << "Input size of square : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> input[i][j];
        }
        cout << endl;
    }
    LUdecomp(input, lower, upper, n);
    cout << "Lower Matrix = " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << lower[i][j] << " ";
        }
        cout << ";" << endl;
    }
    cout << "Upper Matrix = " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << upper[i][j] << " ";
        }
        cout << ";" << endl;
    }
    return 0;
}

void LUdecomp(float InputArray[MAX_MAT_SIZE][MAX_MAT_SIZE], float OutputArray_L[MAX_MAT_SIZE][MAX_MAT_SIZE], float OutputArray_U[MAX_MAT_SIZE][MAX_MAT_SIZE], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j < i) OutputArray_L[j][i] = 0;
            else
            {
                OutputArray_L[j][i] = InputArray[j][i];
                for (int k = 0; k < i; k++)
                {
                    OutputArray_L[j][i] = OutputArray_L[j][i] - OutputArray_L[j][k] * OutputArray_U[k][i];
                }
            }
        }
    }
}