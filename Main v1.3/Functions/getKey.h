#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include <list>
//Parth
using namespace std;

int key[3][3];
void getKey() 
{
	srand(time(0));
	int x;
	while (1) 
	{
		for (int i = 0; i < 9; i++) 
		{
			x = rand() % 1000 + 1;
			key[(i % 3)][(i) / 3] = x;
		}
		if ((key[0][0] * key[1][1] * key[2][2]) + 
			 key[0][1] * key[1][2] * key[2][0] + 
			 key[0][2] * key[1][0] * key[2][1] - 
			 key[2][0] * key[1][1] * key[0][2] - 
			(key[2][1] * key[1][2] * key[0][0]) - 
			(key[2][2] * key[1][0] * key[0][1]) != 0) {
			{
				break;
			}
		}
	}
}