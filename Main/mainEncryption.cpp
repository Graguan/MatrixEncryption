#include <iostream>
#include <iomanip>
#include <Windows.h>
#include "convToASCII.h"
#include "mMatrix.h"
#include "getKey.h"
#include "findInverse.h"
#include "unEncrypt.h"
#include "testPause.h"
using namespace std;
void encrypt();
void decrypt();
int main()
{
	char input;
	while (1)
	{
		cout << "Would you like to encrypt or decrypt? (E/D)" << endl;
		cin >> input;
		if (input == 'E' || input == 'e')
		{
			encrypt();
		}

		else if (input == 'D' || input == 'd')
		{
			decrypt();
		}

		else
		{
			system("CLS");
			cout << "Invalid character! Input a valid character!" << endl;
		}
	}


	system("pause");
	return 0;
	
}
void encrypt()
{
	bool flag = false;
	string text;
	getKey();
	system("CLS");
	cout << "Enter text (up to 840 characters): ";
	cin.ignore();
	getline(cin, text);
	if (text.length() > 840)
	{
		cout << "\nText is too large! Try again!";
		Sleep(1000);
		exit(1);
	}

	convToASCII(text);

	mMatrix(message, key);

	findInverse(key);

	unEncrypt(encrypted, inv);

	for (int i = 0; i < 280; i++)
	{
		cout << setw(3) << i + 1 << " | ";
		for (int j = 1; j <= 3; j++)
		{

			if (encrypted[i][j] == 0)
			{
				flag = true;
				cout << encrypted[i][j - 1];
			}
			else
			{
				cout << encrypted[i][j-1] << " ";
				if (j % 3 == 0)
					cout << endl;
			}
		}
		if (flag)
			break;
	}
	cout << endl;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			if (j % 3 == 0)
				cout << endl;
			cout << key[i][j] << " ";
		}
	cout << endl;
}
void decrypt()
{
	int length;
	system("CLS");
	cout << "(1/3)Enter the number of rows: ";
	cin >> length;
	Sleep(500);
	system("CLS");
	cout << "(2/3)Now, enter the encrypted matrix." << endl;
	Sleep(1000);
	cout << "For example";
	testPause();
	cout << endl;
	for (int i = 0; i < length; i++)
		cout << "123 123 123\n";
	cout << endl << endl;
	for (int i = 0; i < length; i++)
		for (int j = 0; j < 3; j++)
			cin >> encrypted[i][j];
	Sleep(500);
	system("CLS");
	cout << "(3/3)Next, enter the key using the same format as previous." << endl;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> key[i][j];
	cout << "Your unencrypted message is";
	testPause();
	cout << endl;
	findInverse(key);
	unEncrypt(encrypted, inv);
	for (int i = 0; i < 280; i++)
		for (int j = 0; j < 3; j++)
			cout << char(unencrypted[i][j]);
	return;
}