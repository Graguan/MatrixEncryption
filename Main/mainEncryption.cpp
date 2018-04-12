#include <iostream>
#include "convToASCII.h"
#include "mMatrix.h"
#include "getKey.h"
#include "findInverse.h"
#include "unEncrypt.h"
using namespace std;

int main()
{
	string text;

	getKey();

	cout << "Enter text (up to 200 characters): ";
	getline(cin, text);

	convToASCII(text);

	mMatrix(message, key);

	findInverse(key);

	unEncrypt(encrypted, inv);


	for (int i = 0; i < 200; i++)
		for (int j = 0; j < 3; j++)
			cout << char(unencrypted[i][j]);


	system("pause");
	return 0;
	
}
