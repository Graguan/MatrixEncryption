#include <iostream>
#include "convToASCII.h"
#include "mMatrix.h"
#include "getKey.h"
using namespace std;

int main()
{
	string text;
	getKey();


	cout << "Enter text (up to 200 characters): ";
	getline(cin, text);
	convToASCII(text);
	mMatrix(cancer, key);
	cout << endl;
	for (int i = 0; i < 3; i++)
		for (int test = 0; test < 3; test++)
			cout << key[i][test] << endl;
	system("pause");
	return 0;
	
}
