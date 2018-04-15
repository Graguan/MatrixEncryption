#include <string>
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;
int code[8000][3] = { 0 };
//Steven
int convToASCII()
{
	string letter;
	cout << "Enter the code you want to encrypt." << endl;
	cin.ignore();
	getline(cin, letter);
	for (int i = 0; i < letter.length(); i++)
	{
		int x = int(letter.at(i));
		//cout << x << endl;
		code[i / 3][i % 3] = x;
	}
	//cout << letter << endl;
	return letter.length();
}
