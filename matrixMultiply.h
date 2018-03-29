#include <iostream>
using namespace std;

void matrixMultiply(int value[3][3], int key[3][3])
{
	int i, j, k, count = 0, total = 0;

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			for (k = 0; k < 200; k++)
				total += value[i][k] * key[k][j];
			cout << total << ' ';
			++count;
			if (count % 3 == 0)
				cout << endl;
			total = 0;
		}
	}

	return;
}