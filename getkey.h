#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>
using namespace std;
void getKey(void);
int key[3][3];
void getKey(void) {
	srand(time(0));
	int x;
	while (1) {
		for (int i = 1; i <= 9; i++) {
			x = rand() % 10000 + 1;
			key[(i % 3) + 1][(i + 2) / 3] = x;
		}
		if ((key[1][1] * key[2][2] * key[3][3]) + key[1][2] * key[2][3] * key[3][1] + key[1][3] * key[2][1] * key[3][2] - key[3][1] * key[2][2] * key[1][3] - (key[3][2] * key[2][3] * key[1][1]) - (key[3][3] * key[2][1] * key[1][2]) != 0) {
			break;
		}
	}
}
