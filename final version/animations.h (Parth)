//Parth
#include <iostream>;
#include <Windows.h>
using namespace std;
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
                                                      `-\"\"\"-`\n\
";
void animations() {
	for (int i = 0; i < 50; i++)
		printf("\n"); // jump to bottom of console
	printf("%s", rocket);
	int j = 300000;
	for (int i = 0; i < 30; i++) {
		Sleep(500); // move faster and faster,
		j = (int)(j * 0.9); // so sleep less each time
		printf("\n"); // move rocket a line upward
	}
	system("CLS");
}
void setcolor(string x, int y) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), y);
	cout << x << endl;
}
void createdby() {
	for (int i = 0; i < 10; i++) {
		cout << "\n";
	}
	cout << "\t\t\t\t\t       ";
	setcolor("Created By:", 11);
	Sleep(2000);
	cout << "\t\t\t\t\t";
	setcolor("Steven, Parth, And Ankit", 12);
	Sleep(4000);
	system("CLS");
}
