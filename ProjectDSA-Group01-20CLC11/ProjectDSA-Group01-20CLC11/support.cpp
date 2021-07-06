#include "header.h"

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

int flashSortRuntime(int* a, int n) {
	clock_t start, end;
	start = clock();
	flash_sort(a, n);
	end = clock();
	return end-start;
}

int runTime(int algorithm, int* a, int n) {
	switch (algorithm)
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
	default: return 0;
	}
}

unsigned long long compCount(int algorithm, int* a, int n) {
	unsigned long long count_compare = 0;
	switch (algorithm)
	{
	case 1: selection_sort_compare(a, n, count_compare); return count_compare;
	case 2: insertion_sort_compare(a, n, count_compare); return count_compare;
	case 3: bubble_sort_compare(a, n, count_compare); return count_compare;
	case 4: shaker_sort_compare(a, n, count_compare); return count_compare;
	case 5: shell_sort_compare(a, n, count_compare); return count_compare;
	case 6: heap_sort_compare(a, n, count_compare); return count_compare;
	case 7: merge_sort_compare(a, 0, n-1, count_compare); return count_compare;
	case 8: quick_sort_compare(a, 0,n-1, count_compare); return count_compare;
	case 9: counting_sort_compare(a, n, count_compare); return count_compare;
	case 10: radix_sort_compare(a, n, count_compare); return count_compare;
	case 11: flash_sort_compare(a, n, count_compare); return count_compare;
	default: return -1;
	}
}



