#include <iostream> 
//Ankit
using namespace std;

int encrypted[8000][3] = { 0 };
void mMatrix(int A[8000][3], int B[3][3]) {
	int i, j, k, count = 0;
	int total = 0;

	for (i = 0; i < 8000; i++) {
		for (j = 0; j < 3; j++) {
			for (k = 0; k < 3; k++)
				total += A[i][k] * B[k][j];
			encrypted[i][j] = total;
			total = 0;
		}
	}
	return;
}
