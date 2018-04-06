#include <string>
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;
int cancer[200][3];
void convToASCII(string letter)
{
	for (int i = 0; i < letter.length(); i++)
	{
		int x = letter.at(i);
		cancer[i/3][i%3] = x;
	}
	return;
}
