#include "header.h"

/*int* a = nullptr;
	if (argv[1][1] == 'a')
	{
		algorithmMode(argc, argv, a);
	}*/

int main(int argc, char* argv[]) {
	int* a,*b, n, datatype;
	unsigned long long count_compare = 0;
	std::cout << "Enter n: ";
	std::cin >> n;
	std::cout << "Enter data type: ";
	std::cin >> datatype;
	a = new int[n];
	b = new int[n];
	GenerateData(a, n, datatype);
	outputFile("input.txt", a, n);
	clock_t start, end;
	start = clock();
	flash_sort(a, n);
	end = clock();
	//outputFile("output.txt", a, n);
	GenerateData(b, n, datatype);
	std::cout << "Time: " << end - start << " ms\n";
	flash_sort_compare(a, n, count_compare);
	std::cout << "Comparison: " << count_compare;
	return 0;
}