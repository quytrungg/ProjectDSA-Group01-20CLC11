#include "header.h"

//Swap two numbers
void swap_element(int a, int b) {
	int c = a;
	a = b;
	b = c;
}

//1. Bubble sort
void bubble_sort(int* a, int n) {
	//a = new int[n];
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[i]) {
				swap_element(a[i], a[j]);
			}
		}
	}
}

//Bubble sort with comparision
void bubble_sort_compare(int* a, int n, int& count_compare) {
	//a = new int[n];
	count_compare = 0;
	for (int i = 0; ++count_compare && i < n - 1; i++) {
		for (int j = i + 1; ++count_compare &&  j < n; j++) {
			if (++count_compare && a[j] < a[i]) {
				swap_element(a[i], a[j]);
			}
		}
	}
}

//2. Selection sort
void selection_sort(int* a, int n) {
	//a = new int[n];
	int idx = 0;
	for (int i = 0; i < n - 1; i++) {
		idx = i;
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[idx]) {
				idx = j;
			}
		}
		swap_element(a[idx], a[i]);
	}
}

//Selection sort with comparision
void selection_sort_compare(int* a, int n, int& count_compare) {
	//a = new int[n];
	int idx = 0;
	count_compare = 0;
	for (int i = 0; ++count_compare && i < n - 1; i++) {
		idx = i;
		for (int j = i + 1; ++count_compare && j < n; j++) {
			if (++count_compare && a[j] < a[idx]) {
				idx = j;
			}
		}
		swap_element(a[idx], a[i]);
	}
}

//3. Insertion sort
void insertion_sort(int* a, int n) {
	//a = new int[n];
	int key;
	for (int i = 1; i < n; i++) {
		key = a[i];
		int j = i - 1;
		while (a[j] > key && j > 0) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
}

//Insertion sort with comparision
void insertion_sort_compare(int* a, int n, int& count_compare) {
	//a = new int[n];
	int key;
	count_compare = 0;
	for (int i = 1; ++count_compare && i < n; i++) {
		key = a[i];
		int j = i - 1;
		while (++count_compare && a[j] > key && ++count_compare && j > 0) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
}

//4. Shaker sort
void shaker_sort(int* a, int n) {
	//a = new int[n];
	int left = 0, right = n - 1, idx;
	while (left < right) {
		for (int i = right; i > left; i--) {
			if (a[i - 1] > a[i]) {
				swap_element(a[i], a[i - 1]);
				idx = i;
			}
		}
		left = idx;
		for (int i = left; i < right; i++) {
			if (a[i + 1] < a[i]) {
				swap_element(a[i], a[i + 1]);
				idx = i;
			}
		}
		right = idx;
	}
}

//Shaker sort with comparision
void shaker_sort_compare(int* a, int n, int& count_compare) {
	//a = new int[n];
	count_compare = 0;
	int left = 0, right = n - 1, idx;
	while (++count_compare&& left < right) {
		for (int i = right; ++count_compare && i > left; i--) {
			if (++count_compare && a[i - 1] > a[i]) {
				swap_element(a[i], a[i - 1]);
				idx = i;
			}
		}
		left = idx;
		for (int i = left; ++count_compare && i < right; i++) {
			if (++count_compare&& a[i + 1] < a[i]) {
				swap_element(a[i], a[i + 1]);
				idx = i;
			}
		}
		right = idx;
	}
}

//5. Shell sort
void shell_sort(int* a, int n) {
	//a = new int[n];
	for (int interval = n / 2; interval > 0; interval = interval / 2) {
		for (int i = interval; i < n; i++) {
			int temp = a[i], j = i;
			for (j = i; j >= interval && a[j - interval] > temp; j -= interval) {
				a[j] = a[j - interval];
			}
			a[j] = temp;
		}
	}
}

//Shell sort with comparision
void shell_sort_comparision(int* a, int n, int& count_compare) {
	//a = new int[n];
	count_compare = 0;
	for (int interval = n / 2; ++count_compare && interval > 0; interval = interval / 2) {
		for (int i = interval; ++count_compare && i < n; i++) {
			int temp = a[i], j = i;
			for (j = i; ++count_compare && j > interval && ++count_compare && a[j - interval] > temp; j -= interval) {
				a[j] = a[j - interval];
			}
			a[j] = temp;
		}
	}
}

//6. Heap sort


//7. Merge sort
void merge_sort(int* a, int left, int right) {
	if (left < right) {
		int mid = (left + (right - 1)) / 2;
		merge_sort(a, left, mid);
		merge_sort(a, mid + 1, right);
		merge(a, left, mid, right);
	}
}

void merge(int* a, int left, int mid, int right) {
	int n1 = mid - left + 1, n2 = right - mid;
	int* temp1 = new int[n1];
	int* temp2 = new int[n2];
	for (int i = 0; i < right; i++) {
		if (i <= n1) {
			temp1[i] = a[i];
		}
		else {
			temp2[i - n1] = a[i];
		}
	}
	int i = 0, j = 0, idx = left;
	while (i < n1 && j < n2) {
		if (temp1[i] <= temp2[j]) {
			a[idx] = temp1[i];
			i++;
		}
		else {
			a[idx] = temp2[j];
			j++;
		}
		idx++;
	}
	while (i < n1) {
		a[idx] = temp1[i];
	}
	while (j < n2) {
		a[idx] = temp2[j];
	}
}

//Merge sort with comparision
void merge_sort_compare(int* a, int left, int right, int& count_compare) {

}

void merge_compare(int* a, int left, int right, int& count_compare) {

}

