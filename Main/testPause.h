#pragma once
#include <iostream>
#include <Windows.h>
using namespace std;

void testPause()
{
	for (int time = 0; time < 3; time++)
	{
		cout << ".";
		Sleep(1000);
	}
	return;
}