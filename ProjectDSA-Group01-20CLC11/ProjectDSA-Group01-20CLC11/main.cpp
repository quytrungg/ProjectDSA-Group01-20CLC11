#include "header.h"

int main(int argc, char* argv[]) {
	/*int* a = nullptr;
	if (argv[1][1] == 'a')
	{
		algorithmMode(argc, argv, a);
	}*/
	int* a, n, datatype;
	unsigned long long count_compare = 0;
	std::cout << "Enter n: ";
	std::cin >> n;
	std::cout << "Enter data type: ";
	std::cin >> datatype;
	a = new int[n];
	GenerateData(a, n, datatype);
	clock_t start, end;
	start = clock();
	//insert sorting algorithm
	shaker_sort(a, n);
	end = clock();
	outputFile("output.txt", a, n);
	//output time
	std::cout << "Time: " << end - start << " ms\n";
	//insert comparison sorting algorithm
	shaker_sort_compare(a, n, count_compare);
	//output comparison
	std::cout << "Comparison: " << count_compare;
	return 0;
}