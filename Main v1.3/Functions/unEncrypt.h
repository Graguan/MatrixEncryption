#include <iostream> 
#include <cmath>
//Ankit
using namespace std;

int unencrypted[280][3];;
void unEncrypt(int A[280][3], long double B[3][3])
{
	int i, j, k, count = 0;
	long double total = 0;

	for (i = 0; i < 280; i++) 
	{
		for (j = 0; j < 3; j++) 
		{
			for (k = 0; k < 3; k++)
				total += A[i][k] * B[k][j];
			unencrypted[i][j] = round(total);
			total = 0;
		}
	}
	return;
}
