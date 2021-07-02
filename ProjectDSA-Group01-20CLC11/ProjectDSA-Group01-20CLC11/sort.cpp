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

//Bubble sort with comparison
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

//Selection sort with comparison
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

//Insertion sort with comparison
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

//Shaker sort with comparison
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

//Shell sort with comparison
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
void heapify_sort(int* a, int n, int i) {
	int max = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left < n && a[left] > a[max])
		max = left;
	if (right < n && a[right] > a[max])
		max = right;
	if (max != i) {
		swap_element(a[i], a[max]);
		heapify_sort(a, n, max);
	}
}

void heap_sort(int* a, int n) {
	//a = new int[n];
	for (int i = (n - 1) / 2; i >= 0; i--)
		heapify_sort(a, n, i);
	for (int i = n - 1; i > 0; i--)
	{
		swap_element(a[0], a[i]);
		heapify_sort(a, i, 0);
	}
}

//Heap sort with comparison
void heapify_sort_compare(int* a, int n, int i, int& count_compare) {
	int max = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (++count_compare && left < n && ++count_compare && a[left] > a[max])
		max = left;
	if (++count_compare && right < n && ++count_compare && a[right] > a[max])
		max = right;
	if (++count_compare && max != i) {
		swap_element(a[i], a[max]);
		heapify_sort(a, n, max);
	}
}

void heap_sort_compare(int* a, int n, int& count_compare) {
	//a = new int[n];
	for (int i = (n - 1) / 2; ++count_compare && i >= 0; i--)
		heapify_sort(a, n, i);
	for (int i = n - 1; ++count_compare && i > 0; i--)
	{
		swap_element(a[0], a[i]);
		heapify_sort(a, i, 0);
	}
}

//7. Merge sort
void merge_sort(int* a, int left, int right) {
	//a = new int[n];
	if (left < right) {
		int mid = left + (right + 1) / 2;
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
		i++; idx++;
	}
	while (j < n2) {
		a[idx] = temp2[j];
		j++; idx++;
	}
}

//Merge sort with comparison
void merge_sort_compare(int* a, int left, int right, int& count_compare) {
	//a = new int[n];
	if (++count_compare && left < right) {
		int mid = left + (right + 1) / 2;
		merge_sort_compare(a, left, mid, count_compare);
		merge_sort_compare(a, mid + 1, right, count_compare);
		merge_compare(a, left, mid, right, count_compare);
	}
}

void merge_compare(int* a, int left, int mid, int right, int& count_compare) {
	int n1 = mid - left + 1, n2 = right - mid;
	int* temp1 = new int[n1];
	int* temp2 = new int[n2];
	for (int i = 0; ++count_compare && i < right; i++) {
		if (++count_compare && i <= n1) {
			temp1[i] = a[i];
		}
		else {
			temp2[i - n1] = a[i];
		}
	}
	int i = 0, j = 0, idx = left;
	while (++count_compare && i < n1 && ++count_compare && j < n2) {
		if (++count_compare && temp1[i] <= temp2[j]) {
			a[idx] = temp1[i];
			i++;
		}
		else {
			a[idx] = temp2[j];
			j++;
		}
		idx++;
	}
	while (++count_compare && i < n1) {
		a[idx] = temp1[i];
		i++; idx++;
	}
	while (++count_compare && j < n2) {
		a[idx] = temp2[j];
		j++; idx++;
	}
}

//8. Quick sort
void quick_sort(int* a, int left, int right) {
	//a = new int[n];
	int mid = (left + right) / 2, pivot = a[mid];
	int i = left, j = right;
	while (i <= j) {
		while (a[i] < pivot)
			i++;
		while (a[j] > pivot)
			j--;
		if (i <= j) {
			swap_element(a[i], a[j]);
			i++;
			j--;
		}
	}
	if (right - left <= 3)
		return;
	quick_sort(a, left, j);
	quick_sort(a, i, right);
}

//Quick sort with comparison
void quick_sort_compare(int* a, int left, int right, int& count_compare) {
	//a = new int[n];
	int mid = (left + right) / 2, pivot = a[mid];
	int i = left, j = right;
	while (++count_compare && i <= j) {
		while (++count_compare && a[i] < pivot)
			i++; 
		while (++count_compare && a[j] > pivot)
			j--;
		if (++count_compare && i <= j) {
			swap_element(a[i], a[j]);
			i++;
			j--;
		}
	}
	if (++count_compare && right - left <= 3) return;
	quick_sort_compare(a, left, j, count_compare);
	quick_sort_compare(a, i, right, count_compare);
}

//9. Counting sort
void counting_sort(int* a, int n) {
	//a = new int[n];
	int* temp = new int[n];
	int min = a[0], max = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] > max)
			max = a[i];
		else if (a[i] < min)
			min = a[i];
	}
	int idx = max - min + 1;
	int* c = new int[idx] {0};
	for (int i = 0; i < n; i++)
		c[a[i] - min]++;
	for (int i = 1; i < idx; i++)
		c[i] += c[i - 1];
	for (int i = 0; i < n; i++) {
		temp[c[a[i] - min] - 1] = a[i];
		c[a[i] - min]--;
	}
	for (int i = 0; i < n; i++)
		a[i] = temp[i];
}

//Counting sort with comparison
void counting_sort_compare(int* a, int n, int& count_compare) {
	//a = new int[n];
	count_compare = 0;
	int* temp = new int[n];
	int min = a[0], max = a[0];
	for (int i = 1; ++count_compare && i < n; i++) {
		if (++count_compare && a[i] > max)
			max = a[i];
		else if (++count_compare && a[i] < min)
			min = a[i];
	}
	int idx = max - min + 1;
	int* c = new int[idx] {0};
	for (int i = 0; ++count_compare && i < n; i++)
		c[a[i] - min]++;
	for (int i = 1; ++count_compare && i < idx; i++)
		c[i] += c[i - 1];
	for (int i = 0; ++count_compare && i < n; i++) {
		temp[c[a[i] - min] - 1] = a[i];
		c[a[i] - min]--;
	}
	for (int i = 0; ++count_compare && i < n; i++)
		a[i] = temp[i];
}

//10. Radix sort
void radix_sort(int* a, int n) {
	int* temp = new int[n], max = a[0], exp = 1;
	for (int i = 0; i < n; i++) {
		if (a[i] > max)
			max = a[i];
	}
	while (max / exp > 0){
		int* bucket = new int[10]{ 0 };
		for (int i = 0; i < n; i++)
			bucket[a[i] / exp % 10]++;
		for (int i = 1; i < 10; i++)
			bucket[i] += bucket[i - 1];
		for (int i = n - 1; i >= 0; i--)
			temp[--bucket[a[i] / exp % 10]] = a[i];
		for (int i = 0; i < n; i++)
			a[i] = temp[i];
		exp = exp * 10;
	}
}

//Radix sort with comparison
void radix_sort_compare(int* a, int n, int& count_compare) {
	//a = new int[n];
	int* temp = new int[n], max = a[0], exp = 1;
	for (int i = 0; ++count_compare && i < n; i++) {
		if (++count_compare && a[i] > max)
			max = a[i];
	}
	while (++count_compare && max / exp > 0) {
		int* bucket = new int[10]{ 0 };
		for (int i = 0; ++count_compare && i < n; i++)
			bucket[a[i] / exp % 10]++;
		for (int i = 1; ++count_compare && i < 10; i++)
			bucket[i] += bucket[i - 1];
		for (int i = n - 1; ++count_compare && i >= 0; i--)
			temp[--bucket[a[i] / exp % 10]] = a[i];
		for (int i = 0; ++count_compare && i < n; i++)
			a[i] = temp[i];
		exp = exp * 10;
	}
}

//11. Flash sort
void flash_sort(int* a, int n) {
	int min = a[0], max = 0, m = int(0.45 * n);
	int* l = new int[m];
	for (int i = 0; i < m; i++)
		l[i] = 0;
	for (int i = 1; i < n; i++){
		if (a[i] < min)
			min = a[i];
		if (a[i] > a[max])
			max = i;
	}
	if (a[max] == min)
		return;
	double c1 = (double)(m - 1) / (a[max] - min);
	for (int i = 0; i < n; i++) {
		int k = int(c1 * (a[i] - min));
		++l[k];
	}
	for (int i = 1; i < m; i++)
		l[i] += l[i - 1];
	HoanVi(a[max], a[0]);
	int nmove = 0, j = 0, k = m - 1, t = 0, flash;
	while (nmove < n - 1) {
		while (j > l[k] - 1) {
			j++;
			k = int(c1 * (a[j] - min));
		}
		flash = a[j];
		if (k < 0) break;
		while (j != l[k]) {
			k = int(c1 * (flash - min));
			int hold = a[t = --l[k]];
			a[t] = flash;
			flash = hold;
			++nmove;
		}
	}
	delete[] l;
	insertion_sort(a, n);
}

//Flash sort with comparison
void flash_sort_compare(int* a, int n, int& count_compare) {
	int min = a[0], max = 0, m = int(0.45 * n);
	int* l = new int[m];
	for (int i = 0; ++count_compare && i < m; i++)
		l[i] = 0;
	for (int i = 1; ++count_compare && i < n; i++) {
		if (++count_compare && a[i] < min)
			min = a[i];
		if (++count_compare && a[i] > a[max])
			max = i;
	}
	if (++count_compare && a[max] == min)
		return;
	double c1 = (double)(m - 1) / (a[max] - min);
	for (int i = 0; ++count_compare && i < n; i++) {
		int k = int(c1 * (a[i] - min));
		++l[k];
	}
	for (int i = 1; ++count_compare && i < m; i++)
		l[i] += l[i - 1];
	swap_element(a[max], a[0]);
	int nmove = 0, j = 0, k = m - 1, t = 0, flash;
	while (++count_compare && nmove < n - 1) {
		while (++count_compare && j > l[k] - 1) {
			j++;
			k = int(c1 * (a[j] - min));
		}
		flash = a[j];
		if (++count_compare && k < 0) break;
		while (++count_compare && j != l[k]) {
			k = int(c1 * (flash - min));
			int hold = a[t = --l[k]];
			a[t] = flash;
			flash = hold;
			++nmove;
		}
	}
	delete[] l;
	insertion_sort(a, n);
}


//argc, argv
void check_input(int argc, char* argv[]) {

}

