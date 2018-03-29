#include <string>
#include <sstream>
#include <iostream>
using namespace std;

void convToASCII(string letter)
{
	for (int i = 0; i < letter.length(); i++)
	{
		char x = letter.at(i) - 48;
		cout << int(x) << endl;
	}
}
