#include <string>
#include <sstream>
#include <vector>
#include <iostream>
//Steven
using namespace std;
int message[280][3];
void convToASCII(string letter)
{
	for (int i = 0; i < letter.length(); i++)
	{
		int x = letter.at(i);
		message[i/3][i%3] = x;
	}
	return;
}
