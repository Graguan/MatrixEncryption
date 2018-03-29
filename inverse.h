#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>
#include "getkey.h"
using namespace std;
long double inv[3][3];
void getinv(int arr[3][3]) {
	double deter = (arr[1][1] * arr[2][2] * arr[3][3]) + arr[1][2] * arr[2][3] * arr[3][1] + arr[1][3] * arr[2][1] * arr[3][2] - arr[3][1] * arr[2][2] * arr[1][3] - (arr[3][2] * arr[2][3] * arr[1][1]) - (arr[3][3] * arr[2][1] * arr[1][2]);
	//cout << deter<< endl;
	inv[1][1] = (arr[2][2] * arr[3][3] - arr[2][3] * arr[3][2])/deter;
	inv[2][1] = (arr[2][1] * arr[3][3] - arr[2][3] * arr[3][1])*-1/deter;
	inv[3][1] = (arr[2][1] * arr[3][2] - arr[2][2] * arr[3][1])/deter;
	inv[1][2] = (arr[1][2] * arr[3][3] - arr[1][3] * arr[3][2])*-1/deter;
	inv[2][2] = (arr[1][1] * arr[3][3] - arr[1][3] * arr[3][1])/deter;
	inv[3][2] = (arr[1][1] * arr[3][2] - arr[1][2] * arr[3][1])*-1/deter;
	inv[1][3] = (arr[1][2] * arr[2][3] - arr[1][3] * arr[2][2])/deter;
	inv[2][3] = (arr[1][1] * arr[2][3] - arr[1][3] * arr[2][1])*-1/deter;
	inv[3][3] = (arr[1][1] * arr[2][2] - arr[1][2] * arr[2][1])/deter;
	//cout << inv[0][0] << endl;
}
