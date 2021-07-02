#include "header.h"


//	Command 1, 2: sorted array -> "output.txt"
//	Command 2, 5: generated input -> "input.txt"
//	Command 3: random order  -> "input_1.txt"
//			   nearly sorted -> "input_2.txt"
//					  sorted -> "input_3.txt"
//					reversed -> "input_4.txt"

void outputFile(const char* filename, int* a, int n) {
	std::fstream f;
	f.open(filename, std::fstream::out);
	f << n << std::endl;
	for (int i = 0; i < n; i++)
		f << a[i] << " ";
	f.close();
}

void outputFile4(const char* filename, int* a, int n) {	
	std::fstream f(filename, std::fstream::out);
	for (int i = 0; i < 4; i++) {

	}
	f.close();
}
