#include "header.h"


//	Command 1, 2: sorted array -> "output.txt"
//	Command 2, 5: generated input -> "input.txt"
//	Command 3: random order  -> "input_1.txt"
//			   nearly sorted -> "input_2.txt"
//					  sorted -> "input_3.txt"
//					reversed -> "input_4.txt"


void outputFile1(char* filename ,int a[], int n) {
	std::ofstream f;
	f.open(filename, std::ios_base::out);
	if (f.fail()) {
		std::cout << "Cannot open file\n";
		return;
	}
	f << n << std::endl;
	for (int i = 0; i < n; i++)
		f << a[i] << " ";
	f.close();
}

void outputFile2(char* filename, int* a, int n) {
	std::ofstream f;
	f.open(filename, std::ios_base::out);
	if (f.fail()) {
		std::cout << "Cannot open file\n";
		return;
	}
	f << n << std::endl;
	for (int i = 0; i < n; i++)
		f << a[i] << " ";
	f.close();
}
