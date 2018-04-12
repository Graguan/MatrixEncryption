#include <iostream> 
#include <cmath>
//Ankit
using namespace std;

int unencrypted[200][3];;
void unEncrypt(int A[200][3], long double B[3][3]) {
	int i, j, k, count = 0;
	long double total = 0;

	for (i = 0; i < 200; i++) {
		for (j = 0; j < 3; j++) {
			for (k = 0; k < 3; k++)
				total += A[i][k] * B[k][j];
			unencrypted[i][j] = round(total);
			/*cout << total << ' ';
			++count;
			if (count % 3 == 0)
			cout << endl;*/
			total = 0;
		}
	}
	return;
}
