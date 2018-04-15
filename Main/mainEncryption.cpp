#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <fstream>
#include "convToASCII.h"
#include "mMatrix.h"
#include "getKey.h"
#include "findInverse.h"
#include "unEncrypt.h"
#include "testPause.h"
using namespace std;
void encrypt();
void decrypt();
void writeFile();
void readFile();
int main()
{

	char input3,input2,input1;
	while (1)
	{
		cout << "Would you like to encrypt or decrypt?" << endl;
		cout << "1. Encrypt" << endl
		 	 << "2. Decrypt" << endl
			 << "Enter: ";
		cin >> input1;
		if (input1=='1') //Encryption
		{
			system("CLS");
			encrypt();
				while (1) {
					cout << endl << "Would you like to save this information to a text file?" << endl;
					cout << "1. Yes" << endl
						 << "2. No" << endl
						 << "Enter: ";
					cin >> input3;
					if (input3 == '1')
					{
						writeFile();
					}
					else if (input3=='2')
						exit(1);
					else
					{
						system("CLS");
						cerr << "Invalid character! Input a valid character!" << endl;
					}
				}

		}

		else if (input1=='2') // Decryption
		{
			system("CLS");
			cout << "Would you like to read from a file or enter the information?" << endl
				 << "1. Read from a file" << endl
				 << "2. Enter the information" << endl
				 << "Enter: ";
			cin >> input2;
			if (input2 == '1')
			{
				readFile();
			}
			else if (input2 == '2')
				decrypt();
			else
			{
				system("CLS");
				cerr << "Invalid character! Input a valid character!" << endl;
			}

		}

		else //Error
		{
			system("CLS");
			cerr << "Invalid character! Input a valid character!" << endl;
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
		cerr << "\nText is too large! Try again!";
		Sleep(1000);
		exit(1);
	}

	convToASCII(text);

	mMatrix(message, key);

	findInverse(key);

	unEncrypt(encrypted, inv);
	cout << "Encrypted:" << endl;
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
				cout << encrypted[i][j - 1] << " ";
				if (j % 3 == 0)
					cout << endl;
			}
		}
		if (flag)
			break;
	}
	cout << endl << endl << "Key: ";
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			if (j % 3 == 0)
				cout << endl;
			cout << key[i][j] << " ";
		}
	cout << endl;
	return;
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
void writeFile()
{
	system("CLS");
	ofstream outFile;
	string filename;
	cout << "What would you like to name your file? (excluding extension)" << endl;
	cin.ignore();
	getline(cin, filename);
	filename += ".txt";
	outFile.open(filename.c_str() );
	bool flag = false;
	for (int i = 0; i < 3; i++)
		for (int j = 1; j <= 3; j++) {
			outFile << key[i][j - 1] << " ";
			if (j % 3 == 0)
				outFile << endl;
		}
	for (int i = 0; i < 280; i++)
	{
		for (int j = 1; j <= 3; j++)
		{

			if (encrypted[i][j-1] == 0)
			{
				outFile << endl << i << endl;
				flag = true;
				break;
			}
		}
		if (flag)
			break;
	}
	for (int i = 0; i < 280; i++)
	{
		for (int j = 1; j <= 3; j++)
		{

			if (encrypted[i][j - 1] == 0)
			{
				cout << endl << "Saving";
				testPause();
				outFile.close();
				exit(3);
			}
			else
			{
				outFile << encrypted[i][j - 1] << " ";
				if (j % 3 == 0)
					outFile << endl;
			}
		}
	}
}
void readFile()
{
	int length;
	system("CLS");
	ifstream inFile;
	while (1) {
		cout << "What is the name of your file? (excluding extension)" << endl;
		string filename;
		cin.ignore();
		getline(cin, filename);
		filename += ".txt";
		inFile.open(filename.c_str());
		struct stat buf;
		if (stat(filename.c_str(), &buf) != -1)
			break;
		else if (inFile.good())
			break;
		else if (inFile.is_open())
			break;
		/*
		else if (inFile.fail()) {
			cout << "Invalid file!" << endl;
			inFile.clear();
			Sleep(1200);
			system("CLS");
		}
		*/
		else
			cout << "if " << endl;
	}
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			inFile >> key[i][j];
	inFile >> length;
	for (int i = 0; i < length; i++)
		for (int j = 0; j < 3; j++) {
			inFile >> encrypted[i][j];
		}
	cout << "Your unencrypted message is";
	testPause();
	cout << endl;
	findInverse(key);
	unEncrypt(encrypted, inv);
	for (int i = 0; i < length; i++)
		for (int j = 0; j < 3; j++)
			cout << char(unencrypted[i][j]);
	cout << endl;
	Sleep(5000);
	exit(3);
}
