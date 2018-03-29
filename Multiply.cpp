#include <iostream>
#include "matrixMultiply.h"
using namespace std;

int main()
{
int A[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };
int B[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };

matrixMultiply(A, B);
return 0;
}
