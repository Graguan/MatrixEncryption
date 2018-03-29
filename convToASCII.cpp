#include <string>
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

int convToASCII(string letter, int &array)
{
	for (int i = 0; i < letter.length(); i++)
	{
		char x = letter.at(i);
		for (int j = 0; i < 3; i++)
		{
			for (int k = 0; k < 3; k++)
					array[j][k] = x;
		}
	}
	return array;
}
