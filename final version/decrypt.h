#include <iostream>
#include <fstream>
#include <cmath>
#include<iomanip>
#include "inverse.h"
using namespace std;
void decrypt() {
	int count,size1,size2;
	int tkey[3][3];
	int ncode[8000][3];
	int num;
	int unencrypted[8000][3];
	
	//Parth
	ifstream infile;
	ofstream outfile;
	infile.open("C:\\Users\\parth\\source\\repos\\Project1\\Project1\\encrypted.txt");
	infile >> count;
	
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			infile >> num;
			tkey[i][j] = num;
		}

	for (int i = 0; i < count / 3 + 1; i++) 
		for (int j = 0; j < 3; j++) {
			infile >> num;
			ncode[i][j] = num;
			if (count % 3 == 0) 
				if (i == count / 3) 
					break;
		}
	infile.close();
	
	//Ankit
	getinv(tkey);
	long double total = 0;
	for (int i = 0; i < 8000; i++) 
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++)
				total += ncode[i][k] * inv[k][j];
			unencrypted[i][j] = round(total);
			total = 0;
		}

	//Steven, Parth
	cout << "Your encrypted code is " << count << " characters long." << endl << endl;
	cout << "Your key in encrypted.txt is:" << endl;
	Sleep(1000);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			cout << tkey[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	cout << "The encrypted message in ecrypted.txt is:" << endl;
	Sleep(1000);
	for (int i = 0; i < count / 3 + 1; i++) {
		for (int j = 0; j < 3; j++) {
			cout << ncode[i][j] << " ";
			if (count % 3 == 0)
				if (i == count / 3)
					break;
		}
		cout << endl;
	}
	cout << endl;
	cout << "Type any character to see the unencrypted message.";
	cout << endl << endl;
	system("pause");
	outfile.open("C:\\Users\\parth\\source\\repos\\Project1\\Project1\\unencrypted.txt");
	system("CLS");
	cout << "Your unencrypted message is:" << endl;
	for (int i = 0; i<count / 3 + 1; i++) 
		for (int j = 0; j < 3; j++) {
			if (count % 3 == 0) {
				if (i == count / 3) {
					break;
				}
			}
			cout << char(unencrypted[i][j]) ;
			outfile << char(unencrypted[i][j]);
			if(count%3!=0)
				if (i == count / 3 and j == count % 3 - 1)
					break;
		}
	outfile.close();
	cout << endl << endl;
	cout << "The unencrypted message is also in unencrypted.txt under file directory:" << endl;
	cout << "C:\\Users\\parth\\source\\repos\\Project1\\Project1\\unencrypted.txt" << endl << endl << endl;
	}


