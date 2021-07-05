#include "header.h"

void maintemp() {
	int* a, * b, n, datatype;
	unsigned long long count_compare = 0;
	std::cout << "Enter n: ";
	std::cin >> n;
	std::cout << "Enter data type: ";
	std::cin >> datatype;
	a = new int[n];
	GenerateData(a, n, datatype);
	b = copyFile(a, n);
	//outputFile("input.txt", a, n);
	clock_t start, end;
	start = clock();
	shaker_sort(a, n);
	end = clock();
	outputFile("output.txt", a, n);
	std::cout << "Time: " << end - start << " ms\n";
	shaker_sort_compare(b, n, count_compare);
	std::cout << "Comparison: " << count_compare;
}

int main(int argc, char* argv[]) {
	maintemp();
	return 0;
}