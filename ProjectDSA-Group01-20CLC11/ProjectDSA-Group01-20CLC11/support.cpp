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
	case 7: return mergeSortRuntime(a, n, extra);
	case 8: return quickSortRuntime(a, n, extra);
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
	case 7: merge_sort_compare(a, n, extra, count_compare); return count_compare;
	case 8: quick_sort_compare(a, n, extra, count_compare); return count_compare;
	case 9: counting_sort_compare(a, n, count_compare); return count_compare;
	case 10: radix_sort_compare(a, n, count_compare); return count_compare;
	case 11: flash_sort_compare(a, n, count_compare); return count_compare;
	default: return -1;
	}
}

////////////////////////////////////////////////////////////// End of comparison count
void time_count(char* sortType, char* outputPara, int* a, int n, int extra = 0) //n = left, extra = right
{
	float time = runTime(sortType, a, n, extra);
	std::cout << "The time of the sorting algorithm: ";
	if(time != -1)
	{
		std::cout << std::setprecision(2) << time << " ms.\n";
	}
	int comp = compCount(sortType, a, n, extra);
	std::cout << "The comparision count of the sorting algorithm: ";
	if (comp != -1)
	{
		std::cout << comp << " comparision(s).\n";
	}
}
