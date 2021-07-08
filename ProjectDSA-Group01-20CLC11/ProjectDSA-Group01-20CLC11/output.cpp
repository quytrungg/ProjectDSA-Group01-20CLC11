#include "header.h"

void outputFile(std::string filename, int* a, int n) {
	std::fstream f;
	f.open(filename, std::fstream::out);
	f << n << std::endl;
	for (int i = 0; i < n; i++)
		f << a[i] << " ";
	f.close();
}

int inputSize(std::string filename) {
	int n;
	std::fstream f(filename, std::fstream::in);
	f >> n;
	f.close();
	return n;
}

int* inputFile(std::string filename, int n) {
	std::fstream f(filename, std::fstream::in);
	if (!f) {
		std::cout << "Can't open file!"; return nullptr;
	}
	f >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		f >> a[i];
	}
	f.close();
	return a;
}

int* copyFile(int* a, int n) {
	int* b = new int[n];
	for (int i = 0; i < n; i++) {
		b[i] = a[i];
	}
	return b;
}