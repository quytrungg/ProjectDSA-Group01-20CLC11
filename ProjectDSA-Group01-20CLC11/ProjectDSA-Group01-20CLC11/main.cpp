#include "header.h"

int main(int argc, char* argv[]) {
	int* a = nullptr;
	if (argv[1][1] == 'a')
	{
		algorithmMode(argc, argv, a);
	}
	//int* a, n, datatype, count_compare = 0;
	//std::cout << "Enter n: ";
	//std::cin >> n;
	//std::cout << "Enter data type: ";
	//std::cin >> datatype;
	//a = new int[n];
	//GenerateData(a, n, datatype);
	//clock_t start, end;
	//start = clock();
	////insert sorting algorithm
	//merge_sort(a, 0, n - 1);
	//end = clock();
	////output time
	//std::cout << "Time: " << end - start << " ms\n";
	////insert comparison sorting algorithm
	//merge_sort_compare(a, 0, n - 1, count_compare);
	////output comparison
	//std::cout << "Comparison: " << count_compare;
	return 0;
}