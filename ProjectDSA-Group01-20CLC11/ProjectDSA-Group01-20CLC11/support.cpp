#include "header.h"

///////////////// RunTime ////////////////

int selectionSortRuntime(int* a, int n) {
	clock_t start, end;
	start = clock();
	selection_sort(a, n);
	end = clock();
	return end-start;
}

int insertionSortRuntime(int* a, int n) {
	clock_t start, end;
	start = clock();
	insertion_sort(a, n);
	end = clock();
	return end-start;
}

int bubbleSortRuntime(int* a, int n) {
	clock_t start, end;
	start = clock();
	bubble_sort(a, n);
	end = clock();
	return end-start;
}

int shakerSortRuntime(int* a, int n) {
	clock_t start, end;
	start = clock();
	shaker_sort(a, n);
	end = clock();
	return end-start;
}

int shellSortRuntime(int* a, int n) {
	clock_t start, end;
	start = clock();
	shell_sort(a, n);
	end = clock();
	return end-start;
}

int heapSortRuntime(int* a, int n) {
	clock_t start, end;
	start = clock();
	heap_sort(a, n);
	end = clock();
	return end-start;
}

int mergeSortRuntime(int* a, int left, int right) {
	clock_t start, end;
	start = clock();
	merge_sort(a, left, right);
	end = clock();
	return end-start;
}

int quickSortRuntime(int* a, int left, int right) {
	clock_t start, end;
	start = clock();
	quick_sort(a, left, right);
	end = clock();
	return end-start;
}

int countingSortRuntime(int* a, int n) {
	clock_t start, end;
	start = clock();
	counting_sort(a, n);
	end = clock();
	return end-start;
}

int radixSortRuntime(int* a, int n) {
	clock_t start, end;
	start = clock();
	radix_sort(a, n);
	end = clock();
	return end-start;
}

double flashSortRuntime(int* a, int n) {
	clock_t start, end;
	start = clock();
	flash_sort(a, n);
	end = clock();
	return end-start;
}

//main runtime calculator (-1 = error) n = left, extra = right
double runTime(char* sortType, int* a, int n) {
	int type = 0;
	if (strcmp(sortType, "selection-sort") == 0) type = 1;
	else if (strcmp(sortType, "insertion-sort") == 0) type = 2;
	else if (strcmp(sortType, "bubble-sort") == 0) type = 3;
	else if (strcmp(sortType, "shaker-sort") == 0) type = 4;
	else if (strcmp(sortType, "shell-sort") == 0) type = 5;
	else if (strcmp(sortType, "heap-sort") == 0) type = 6;
	else if (strcmp(sortType, "merge-sort") == 0) type = 7;
	else if (strcmp(sortType, "quick-sort") == 0) type = 8;
	else if (strcmp(sortType, "counting-sort") == 0) type = 9;
	else if (strcmp(sortType, "radix-sort") == 0) type = 10;
	else if (strcmp(sortType, "flash-sort") == 0) type = 11;
	switch (type)
	{
	case 1: return selectionSortRuntime(a, n);
	case 2: return insertionSortRuntime(a, n);
	case 3: return bubbleSortRuntime(a, n);
	case 4: return shakerSortRuntime(a, n);
	case 5: return shellSortRuntime(a, n);
	case 6: return heapSortRuntime(a, n);
	case 7: return mergeSortRuntime(a, 0, n-1);
	case 8: return quickSortRuntime(a, 0, n-1);
	case 9: return countingSortRuntime(a, n);
	case 10: return radixSortRuntime(a, n);
	case 11: return flashSortRuntime(a, n);
	default: return -1;
	}
}

////////////////////////////////////////////////////////////// End of runtime


///////////////// Comparison Count ////////////////

//main runtime calculator (-1 = error) n = left, extra = right
int compCount(char* sortType, int* a, int n) {
	unsigned long long count_compare = 0;
	int type = 0;

	if (strcmp(sortType, "selection-sort") == 0) type = 1;
	else if (strcmp(sortType, "insertion-sort") == 0) type = 2;
	else if (strcmp(sortType, "bubble-sort") == 0) type = 3;
	else if (strcmp(sortType, "shaker-sort") == 0) type = 4;
	else if (strcmp(sortType, "shell-sort") == 0) type = 5;
	else if (strcmp(sortType, "heap-sort") == 0) type = 6;
	else if (strcmp(sortType, "merge-sort") == 0) type = 7;
	else if (strcmp(sortType, "quick-sort") == 0) type = 8;
	else if (strcmp(sortType, "counting-sort") == 0) type = 9;
	else if (strcmp(sortType, "radix-sort") == 0) type = 10;
	else if (strcmp(sortType, "flash-sort") == 0) type = 11;
	switch (type)
	{
	case 1: selection_sort_compare(a, n, count_compare); return count_compare;
	case 2: insertion_sort_compare(a, n, count_compare); return count_compare;
	case 3: bubble_sort_compare(a, n, count_compare); return count_compare;
	case 4: shaker_sort_compare(a, n, count_compare); return count_compare;
	case 5: shell_sort_comparision(a, n, count_compare); return count_compare;
	case 6: heap_sort_compare(a, n, count_compare); return count_compare;
	case 7: merge_sort_compare(a, 0, n-1, count_compare); return count_compare;
	case 8: quick_sort_compare(a, 0,n-1, count_compare); return count_compare;
	case 9: counting_sort_compare(a, n, count_compare); return count_compare;
	case 10: radix_sort_compare(a, n, count_compare); return count_compare;
	case 11: flash_sort_compare(a, n, count_compare); return count_compare;
	default: return -1;
	}
}

////////////////////////////////////////////////////////////// End of comparison count

/*time_count example:
* time_count(argv[a], argv[b], a, n); or time_count(argv[a], argv[b], a, left, right);
* The time of the sorting algorithm: 000ms.
* The comparision count of the sorting algorithm: 000 comparision(s).*/

//n = left, extra = right
void time_count(char* sortType, char* outputPara, int* a, int n) {
	double time = runTime(sortType, a, n);
	int comp = compCount(sortType, a, n);
	std::cout << "---------------------------------------\n";
	if (strcmp(outputPara,"-time") == 0 || strcmp(outputPara,"-both") == 0)
	{
		std::cout << "The time of the sorting algorithm: ";
		if (time != -1)
		{
			std::cout  << time << "ms.\n";
		}
		else
		{
			std::cout << "error";
		}
	}
	if (strcmp(outputPara,"-comp") == 0 || strcmp(outputPara, "-both") == 0)
	{
		std::cout << "The comparision count of the sorting algorithm: ";
		if (comp != -1)
		{
			std::cout << comp << " comparision(s).\n";
		}
		else
		{
			std::cout << "error\n";
		}
	}
	std::cout << std::endl;
	return;
} 

void algorithmMode(int argc, char* argv[], int*& a) {
	std::cout << "ALGORITHM MODE\n";
	std::cout << "Algorithm: " << argv[2] << std::endl;
	if (isalpha(argv[3][0])) //command1
	{
		std::cout << "Input file: " << argv[3] << std::endl;
		std::cout << "Input size: " << /*file size*/ std::endl;
		//do the things
	}
	else if (!isalpha(argv[3][0]) && argc == 5)//command3
	{
		std::cout << "Input size: " << argv[3] << "\n\n";
		for (int i = 0; i < 4; i++ )
		{
			std::cout << "Input order: ";
			switch (i)
			{
			case 0:
				std::cout << "Randomize\n";
				break;
			case 1:	
				std::cout << "Sorted\n";
				break;
			case 2:	
				std::cout << "Reversed\n";
				break;
			case 3:	
				std::cout << "Nearly Sorted\n";
				break;
			}
			a = new int[std::stoi(argv[3])];
			GenerateData(a, std::stoi(argv[3]), i);
			time_count(argv[2], argv[4], a, std::stoi(argv[3]));
		}
	}
	else if (!isalpha(argv[3][0]) && argc == 6) //command3
	{
		std::cout << "Input size: " << argv[3] << "\n";
		int inOr = -1;
		if (argv[4] == "-rand") inOr = 0;
		else if (argv[4] == "-nsorted") inOr = 3;
		else if (argv[4] == "-sorted") inOr = 1;
		else if (argv[4] == "-rev") inOr = 2;
		GenerateData(a, std::stoi(argv[3]), inOr);
		time_count(argv[2], argv[5], a, std::stoi(argv[3]));
	}
}
