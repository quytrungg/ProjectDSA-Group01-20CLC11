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
	/*int C = 0, mode = 0, algorithm1 = 0, algorithm2 = 0, size = 0, order = 0, outmode = 0;
	std::string filename;

	check_command(argc, argv, C, mode, algorithm1, algorithm2, size, order, outmode, filename);

	if (C == 1) { command_1(argv, algorithm1, outmode, filename); }
	if (C == 2) { command_2(argv, algorithm1, size, order, outmode); }
	if (C == 3) { command_3(argv, algorithm1, size, outmode); }
	if (C == 4) { command_4(argv, algorithm1, algorithm2, filename); }
	if (C == 5) { command_5(argv, algorithm1, algorithm2, size, order, filename); }*/

	maintemp();
	return 0;
}