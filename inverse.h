#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>
#include "getkey.h"
using namespace std;
long double inv[3][3];
void getinv(int arr[3][3]) {
	double deter = (arr[0][0] * arr[1][1] * arr[2][2]) + arr[0][1] * arr[1][2] * arr[2][0] + arr[0][2] * arr[1][0] * arr[2][1] - arr[2][0] * arr[1][1] * arr[0][2] - (arr[2][1] * arr[1][2] * arr[0][0]) - (arr[2][2] * arr[1][0] * arr[0][1]);
	//cout << deter<< endl;
	inv[0][0] = (arr[0][0] * arr[1][1] - arr[0][1] * arr[1][0])/deter;
	inv[1][0] = (arr[1][0] * arr[2][2] - arr[1][2] * arr[2][0])*-1/deter;
	inv[2][0] = (arr[1][0] * arr[2][1] - arr[1][1] * arr[2][0])/deter;
	inv[0][1] = (arr[0][1] * arr[2][2] - arr[0][2] * arr[2][1])*-1/deter;
	inv[1][1] = (arr[0][0] * arr[2][2] - arr[0][2] * arr[2][0])/deter;
	inv[2][1] = (arr[0][0] * arr[2][1] - arr[0][1] * arr[2][0])*-1/deter;
	inv[0][2] = (arr[0][1] * arr[1][2] - arr[0][2] * arr[1][1])/deter;
	inv[1][2] = (arr[0][0] * arr[1][2] - arr[0][2] * arr[1][0])*-1/deter;
	inv[2][2] = (arr[0][0] * arr[1][1] - arr[0][1] * arr[1][0])/deter;
	//cout << inv[0][0] << endl;
}
