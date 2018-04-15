#include "stringtoascii.h"
#include "multiply.h"
#include "getkey.h"
#include <iostream>
#include <fstream>
using namespace std;
//Steven
int encrypt() {
	int length;
	length= convToASCII();
	
	getKey();
	mMatrix(code, key);
	
	ofstream outfile;
	outfile.open("C:\\Users\\parth\\source\\repos\\Project1\\Project1//encrypted.txt");
	outfile << (length)<< endl << endl;
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			outfile << key[i][j] << " ";
		outfile << endl;
	}
	
	outfile << endl;
	for (int i = 0; i < 8000; i++) {
		if (length <= (i * 3 ))
			break;
		for (int j = 0; j < 3; j++) 
			outfile << encrypted[i][j] << " ";
		outfile << endl;
	}
	outfile.close();
	return length;
}
