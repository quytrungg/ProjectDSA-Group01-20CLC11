#include "header.h"

///////////////// RunTime ////////////////

double selectionSortRuntime(int* a, int n)
{
	clock_t t;
	t = clock();
	selection_sort(a, n);
	t = clock() - t;
	return (float(t) / CLOCKS_PER_SEC)*1000;
}

double insertionSortRuntime(int* a, int n)
{
	clock_t t;
	t = clock();
	insertion_sort(a, n);
	t = clock() - t;
	return (float(t) / CLOCKS_PER_SEC) * 1000;
}

double bubbleSortRuntime(int* a, int n)
{
	clock_t t;
	t = clock();
	bubble_sort(a, n);
	t = clock() - t;
	return (float(t) / CLOCKS_PER_SEC) * 1000;
}

double shakerSortRuntime(int* a, int n)
{
	clock_t t;
	t = clock();
	shaker_sort(a, n);
	t = clock() - t;
	return (float(t) / CLOCKS_PER_SEC) * 1000;
}

double shellSortRuntime(int* a, int n)
{
	clock_t t;
	t = clock();
	shell_sort(a, n);
	t = clock() - t;
	return (float(t) / CLOCKS_PER_SEC) * 1000;
}

double heapSortRuntime(int* a, int n)
{
	clock_t t;
	t = clock();
	heap_sort(a, n);
	t = clock() - t;
	return (float(t) / CLOCKS_PER_SEC) * 1000;
}

double mergeSortRuntime(int* a, int left, int right)
{
	clock_t t;
	t = clock();
	merge_sort(a, left, right);
	t = clock() - t;
	return (float(t) / CLOCKS_PER_SEC) * 1000;
}

double quickSortRuntime(int* a, int left, int right)
{
	clock_t t;
	t = clock();
	quick_sort(a, left, right);
	t = clock() - t;
	return (float(t) / CLOCKS_PER_SEC) * 1000;
}

double countingSortRuntime(int* a, int n)
{
	clock_t t;
	t = clock();
	counting_sort(a, n);
	t = clock() - t;
	return (float(t) / CLOCKS_PER_SEC) * 1000;
}

double radixSortRuntime(int* a, int n)
{
	clock_t t;
	t = clock();
	radix_sort(a, n);
	t = clock() - t;
	return (float(t) / CLOCKS_PER_SEC) * 1000;
}

double flashSortRuntime(int* a, int n)
{
	clock_t t;
	t = clock();
	flash_sort(a, n);
	t = clock() - t;
	return (float(t) / CLOCKS_PER_SEC) * 1000;
}

double runTime(char* sortType, int* a, int n, int extra = 0) //main runtime calculator (-1 = error) n = left, extra = right
{
	int type = 0;
	if (sortType == "selection-sort") type = 1;
	else if (sortType == "insertion-sort") type = 2;
	else if (sortType == "bubble-sort") type = 3;
	else if (sortType == "shaker-sort") type = 4;
	else if (sortType == "shell-sort") type = 5;
	else if (sortType == "heap-sort") type = 6;
	else if (sortType == "merge-sort") type = 7;
	else if (sortType == "quick-sort") type = 8;
	else if (sortType == "counting-sort") type = 9;
	else if (sortType == "radix-sort") type = 10;
	else if (sortType == "flash-sort") type = 11;
	switch (type)
	{
	case 1: return selectionSortRuntime(a, n);
	case 2: return insertionSortRuntime(a, n);
	case 3: return bubbleSortRuntime(a, n);
	case 4: return shakerSortRuntime(a, n);
	case 5: return shellSortRuntime(a, n);
	case 6: return heapSortRuntime(a, n);
	case 7: return mergeSortRuntime(a, extra, n-1);
	case 8: return quickSortRuntime(a, extra, n-1);
	case 9: return countingSortRuntime(a, n);
	case 10: return radixSortRuntime(a, n);
	case 11: return flashSortRuntime(a, n);
	default: return -1;
	}
}

////////////////////////////////////////////////////////////// End of runtime


///////////////// Comparison Count ////////////////

int compCount(char* sortType, int* a, int n, int extra = 0) //main runtime calculator (-1 = error) n = left, extra = right
{
	int count_compare = 0, type = 0;

	if (sortType == "selection-sort") type = 1;
	else if (sortType == "insertion-sort") type = 2;
	else if (sortType == "bubble-sort") type = 3;
	else if (sortType == "shaker-sort") type = 4;
	else if (sortType == "shell-sort") type = 5;
	else if (sortType == "heap-sort") type = 6;
	else if (sortType == "merge-sort") type = 7;
	else if (sortType == "quick-sort") type = 8;
	else if (sortType == "counting-sort") type = 9;
	else if (sortType == "radix-sort") type = 10;
	else if (sortType == "flash-sort") type = 11;
	switch (type)
	{
	case 1: selection_sort_compare(a, n, count_compare); return count_compare;
	case 2: insertion_sort_compare(a, n, count_compare); return count_compare;
	case 3: bubble_sort_compare(a, n, count_compare); return count_compare;
	case 4: shaker_sort_compare(a, n, count_compare); return count_compare;
	case 5: shell_sort_comparision(a, n, count_compare); return count_compare;
	case 6: heap_sort_compare(a, n, count_compare); return count_compare;
	case 7: merge_sort_compare(a, extra, n-1, count_compare); return count_compare;
	case 8: quick_sort_compare(a, extra,n-1, count_compare); return count_compare;
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

void time_count(char* sortType, char* outputPara, int* a, int n, int extra = 0) //n = left, extra = right
{
	double time = runTime(sortType, a, n);
	int comp = compCount(sortType, a, n);
	std::cout << "---------------------------------------\n";
	if (outputPara == "-time" || outputPara == "-both")
	{
		std::cout << "The time of the sorting algorithm: ";
		if (time != -1)
		{
			std::cout << std::setprecision(2) << time << "ms.\n";
		}
		else
		{
			std::cout << "error";
		}
	}
	else if (outputPara == "-comp" || outputPara == "-both")
	{
		std::cout << "The comparision count of the sorting algorithm: ";
		if (comp != -1)
		{
			std::cout << comp << " comparision(s).\n";
		}
		else
		{
			std::cout << "error";
		}
	}
	return;
} 

void algorithmMode(int argc, char* argv[], int a[])
{
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
		time_count(argv[2], argv[5], a, std::stoi(argv[3]);
	}
}
