#include <fstream>
#include <iomanip>
#include "Functions/convToASCII.h"
#include "Functions/mMatrix.h"
#include "Functions/getKey.h"
#include "Functions/findInverse.h"
#include "Functions/unEncrypt.h"
using namespace std;
//Parth and Steven

void setcolor(string x, int y)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), y);
	cout << x;
}
void animations()
{
	const char rocket[] =
"                                                         _\n\
                                                        /E\\\n\
                                                        |N|\n\
                                                        |C|\n\
                                                        |R|\n\
                                                        |Y|\n\
                                                        |P|\n\
                                                        |T|\n\
                                                       /|I|\\\n\
                                                      / |O| \\\n\
                                                     |  |N|  |\n\
";
	for (int i = 0; i < 50; i++)
		cout << "\n"; // jump to bottom of console
	cout << rocket;
	setcolor("                                                      `-\"\"\"-`\n", 12);
	int j = 500;
	for (int i = 0; i < 30; i++)
	{
		Sleep(j); // move faster and faster,
		j *= 0.95; // so sleep less each time
		cout << "\n"; // move rocket a line upward
	}
	system("CLS");
}
void createdby() {
	system("CLS");
	for (int i = 0; i < 10; i++)
	{
		cout << "\n";
	}
	cout << "\t\t\t\t\t       ";
	setcolor("Created By:\n", 11);
	Sleep(2000);
	cout << "\t\t\t\t\t";
	setcolor("Steven, Parth, And Ankit", 12);
	Sleep(4000);
	system("CLS");
}
void testPause()
{
	for (int time = 0; time < 3; time++)
	{
		cout << ".";
		Sleep(1000);
	}
	return;
}
void encrypt()
{
	bool flag = false;
	string text;
	getKey();
	system("CLS");
	setcolor("Enter text (up to 840 characters): ", 11);
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
	Sleep(5000);
	exit(3);
}
void writeFile()
{
	system("CLS");
	ofstream outFile;
	string filename, directory;
	cout << "What would you like to name your file? (excluding extension)" << endl;
	cin.ignore();
	getline(cin, filename);
	filename += ".txt";
	directory = "Messages/";
	directory += filename;
	outFile.open(directory.c_str());
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

			if (encrypted[i][j - 1] == 0)
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
		string filename, directory;
		cin.ignore();
		getline(cin, filename);
		filename += ".txt";
		directory = "Messages/";
		directory += filename;
		inFile.open(directory.c_str());
		struct stat buf;
		if (stat(filename.c_str(), &buf) != -1)
			break;
		else if (inFile.good())
			break;
		else if (inFile.is_open())
			break;
		else
			inFile.clear();
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