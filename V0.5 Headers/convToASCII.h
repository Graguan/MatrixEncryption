#include <string>
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;
int array[200][3];
void convToASCII(string letter)
{
	for (int i = 0; i < letter.length(); i++)
	{
		char x = letter.at(i);
		for (int j = 0; j < 200; j++)
		{
			for (int k = 0; k < 3; k++)
					array[j][k] = x;
		}
	}
	return;
}
