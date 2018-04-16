#include "mainFunctions.h"
using namespace std;
int main()
{
	animations();
	createdby();

	char input1, input2, input3;
	while (1)
	{
		setcolor("Would you like to encrypt or decrypt?\n", 12);
		setcolor("1. Encrypt\n", 11);
		setcolor("2. Decrypt\n", 10);
		setcolor("Enter: ", 12);
		cin >> input1;
		if (input1=='1') //Encryption
		{
			system("CLS");
			encrypt();
				while (1) {
					setcolor("\nWould you like to save this information to a text file?\n", 11);
					cout << "1. Yes" << endl
						 << "2. No" << endl
						 << "Enter: ";
					cin >> input3;
					if (input3 == '1')
					{
						writeFile(); //Saving to txt
					}
					else if (input3=='2')
						exit(1); //Not Saving
					else
					{
						system("CLS");
						cerr << "Invalid character! Input 1 or 2!" << endl; //Error
					}
				}

		}

		else if (input1=='2') // Decryption
		{
			system("CLS");
			setcolor("Would you like to read from a file or enter the information?\n", 10);
			cout << "1. Read from a file" << endl
				 << "2. Enter the information" << endl
				 << "Enter: ";
			cin >> input2;
			if (input2 == '1') //Reading from txt
			{
				readFile(); 
			}
			else if (input2 == '2') //Manually Entering
				decrypt(); 
			else //Error
			{
				system("CLS");
				cerr << "Invalid character! Input 1 or 2!" << endl; 
			}

		}

		else //Error
		{
			system("CLS");
			cerr << "Invalid character! Input 1 or 2!" << endl;
		}
	}


	system("pause");
	return 0;
}

