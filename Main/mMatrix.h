#include <iostream> 
using namespace std;

int encrypted[200][3];;
void mMatrix(int A[200][3], int B[3][3]) {
	int i, j, k, count = 0, total = 0;

	for (i = 0; i < 200; i++) {
		for (j = 0; j < 3; j++) {
			for (k = 0; k < 3; k++)
				total += A[i][k] * B[k][j];
			cout << total << ' ';
			++count;
			if (count % 3 == 0)
				cout << endl;
			total = 0;
		}
	}
	return;
}