#include "header.h"

//1. Bubble sort
void bubble_sort(int* a, int n) {
	//a = new int[n];
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[i]) {
				HoanVi(a[i], a[j]);
			}
		}
	}
}

//Bubble sort with comparison
void bubble_sort_compare(int* a, int n,unsigned long long & count_compare) {
	//a = new int[n];
	count_compare = 0;
	for (int i = 0; ++count_compare && i < n - 1; i++) {
		for (int j = i + 1; ++count_compare &&  j < n; j++) {
			if (++count_compare && a[j] < a[i]) {
				HoanVi(a[i], a[j]);
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
		HoanVi(a[idx], a[i]);
	}
}

//Selection sort with comparison
void selection_sort_compare(int* a, int n, unsigned long long & count_compare) {
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
		HoanVi(a[idx], a[i]);
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
void insertion_sort_compare(int* a, int n, unsigned long long & count_compare) {
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
	int Left = 0;
	int Right = n - 1;
	int k = 0;
	while ( Left < Right)
	{
		for (int i = Left; i < Right; i++)
		{
			if ( a[i] > a[i + 1])
			{
				HoanVi(a[i], a[i + 1]);
				k = i;
			}
		}
		Right = k;
		for (int i = Right; i > Left; i--)
		{
			if ( a[i] < a[i - 1])
			{
				HoanVi(a[i], a[i - 1]);
				k = i;
			}
		}
		Left = k;
	}
}

//Shaker sort with comparison
void shaker_sort_compare(int* a, int n, unsigned long long & count_compare) {
	//a = new int[n];
	int Left = 0;
	int Right = n - 1;
	int k = 0;
	while (++count_compare && Left < Right)
	{
		for (int i = Left; ++count_compare && i < Right; i++)
		{
			if (++count_compare && a[i] > a[i + 1])
			{
				HoanVi(a[i], a[i + 1]);
				k = i;
			}
		}
		Right = k;
		for (int i = Right; ++count_compare && i > Left; i--)
		{
			if (++count_compare && a[i] < a[i - 1])
			{
				HoanVi(a[i], a[i - 1]);
				k = i;
			}
		}
		Left = k;
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
void shell_sort_compare(int* a, int n, unsigned long long & count_compare) {
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
		HoanVi(a[i], a[max]);
		heapify_sort(a, n, max);
	}
}

void heap_sort(int* a, int n) {
	//a = new int[n];
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify_sort(a, n, i);
	for (int i = n - 1; i > 0; i--)
	{
		HoanVi(a[0], a[i]);
		heapify_sort(a, i, 0);
	}
}

//Heap sort with comparison
void heapify_sort_compare(int* a, int n, int i, unsigned long long & count_compare) {
	int root = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (++count_compare && left < n && ++count_compare && a[left] > a[root]) {
		root = left;
	}
	if (++count_compare && right < n && ++count_compare && a[right] > a[root]) {
		root = right;
	}
	if (++count_compare && root != i) {
		HoanVi(a[i], a[root]);
		heapify_sort_compare(a, n, root, count_compare);
	}
}

void heap_sort_compare(int* a, int n, unsigned long long & count_compare) {
	//a = new int[n];
	int i = (n - 1) / 2;
	while (++count_compare && i >= 0) {
		heapify_sort_compare(a, n, i, count_compare);
		i -= 1;
	}
	int j = n - 1;
	while (++count_compare && j >= 0) {
		HoanVi(a[0], a[j]);
		heapify_sort_compare(a, i, 0, count_compare);
		j -= 1;
	}
}

//7. Merge sort
void merge_sort(int* a, int left, int right) {
	//a = new int[n];
	if (right > left)
	{
		int mid; // Phan tu o giua
		mid = (left + right) / 2;
		merge_sort(a, left, mid); // Goi de quy mang con ben trai
		merge_sort(a, mid + 1, right); // Goi de quy mang con ben phai
		merge(a, left, mid, right); // Goi ham so sanh hai mang con
	}
}

void merge(int* a, int left, int mid, int right) {
	int* temp; // Khoi tao mang tam de sap xep
	int i = left; // Vi tri phan tu dau tien cua mang con ben trai
	int j = mid + 1; // Vi tri phan tu dau tien cua mang con ben phai

	temp = new int[right - left + 1]; // Khoi tao so luong phan tu cua mang tam

	for (int k = 0; k <= right - left; k++)
	{
		// Kiem phan tu cua mang con ben trai va ben phai
		if (a[i] < a[j])
		{
			// Neu a[i] < a[j] thi copy phan tu ben trai vao mang tam
			temp[k] = a[i];
			i++; // Vi tri phan tu tiep theo cua mang
		}
		else // Nguoc lai copy phan tu cua mang con ben phai vao mang tam
		{
			temp[k] = a[j];
			j++; // Vi tri phan tu tiep theo cua mang
		}

		// Kiem tra mang con ben trai con phan tu nao khong
		if (i == mid + 1)
		{
			// Nguoc lai dua cac phan tu con lai cua mang con ben phai vao mang tam
			while (j <= right)
			{
				k++;
				temp[k] = a[j];
				j++;
			}
			break;
		}

		// Kiem tra mang con ben phai con phan tu nao khong
		if (j == right + 1)
		{
			// Nguoc lai dua cac phan tu con lai cua mang con ben phai vao mang tam
			while (i <= mid)
			{
				k++;
				temp[k] = a[i];
				i++;
			}
			break;
		}
	}

	for (int k = 0; k <= right - left; k++) // Chep mang tam vao mang chinh
		a[left + k] = temp[k];
	delete temp;
}

//Merge sort with comparison
void merge_sort_compare(int* a, int left, int right, unsigned long long& count_compare) {
	//a = new int[n];
	if (++count_compare && right > left)
	{
		int mid; // Phan tu o giua
		mid = (left + right) / 2;
		merge_sort_compare(a, left, mid, count_compare); // Goi de quy mang con ben trai
		merge_sort_compare(a, mid + 1, right, count_compare); // Goi de quy mang con ben phai
		merge_compare(a, left, mid, right, count_compare); // Goi ham so sanh hai mang con
	}
}

void merge_compare(int* a, int left, int mid, int right, unsigned long long& count_compare) {
	int* temp; // Khoi tao mang tam de sap xep
	int i = left; // Vi tri phan tu dau tien cua mang con ben trai
	int j = mid + 1; // Vi tri phan tu dau tien cua mang con ben phai

	temp = new int[right - left + 1]; // Khoi tao so luong phan tu cua mang tam

	for (int k = 0; ++count_compare && k <= right - left; k++)
	{
		// Kiem phan tu cua mang con ben trai va ben phai
		if (++count_compare && a[i] < a[j])
		{
			// Neu a[i] < a[j] thi copy phan tu ben trai vao mang tam
			temp[k] = a[i];
			i++; // Vi tri phan tu tiep theo cua mang
		}
		else // Nguoc lai copy phan tu cua mang con ben phai vao mang tam
		{
			temp[k] = a[j];
			j++; // Vi tri phan tu tiep theo cua mang
		}

		// Kiem tra mang con ben trai con phan tu nao khong
		if (++count_compare && i == mid + 1)
		{
			// Nguoc lai dua cac phan tu con lai cua mang con ben phai vao mang tam
			while (++count_compare && j <= right)
			{
				k++;
				temp[k] = a[j];
				j++;
			}
			break;
		}

		// Kiem tra mang con ben phai con phan tu nao khong
		if (++count_compare && j == right + 1)
		{
			// Nguoc lai dua cac phan tu con lai cua mang con ben phai vao mang tam
			while (++count_compare && i <= mid)
			{
				k++;
				temp[k] = a[i];
				i++;
			}
			break;
		}
	}

	for (int k = 0; ++count_compare && k <= right - left; k++) // Chep mang tam vao mang chinh
		a[left + k] = temp[k];
	delete temp;
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
			HoanVi(a[i], a[j]);
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
void quick_sort_compare(int* a, int left, int right, unsigned long long & count_compare) {
	//a = new int[n];
	int mid = (left + right) / 2, pivot = a[mid];
	int i = left, j = right;
	while (++count_compare && i <= j) {
		while (++count_compare && a[i] < pivot)
			i++; 
		while (++count_compare && a[j] > pivot)
			j--;
		if (++count_compare && i <= j) {
			HoanVi(a[i], a[j]);
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
void counting_sort_compare(int* a, int n, unsigned long long & count_compare) {
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
void radix_sort_compare(int* a, int n, unsigned long long & count_compare) {
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
void flash_sort_compare(int* a, int n, unsigned long long & count_compare) {
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
	HoanVi(a[max], a[0]);
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
	insertion_sort_compare(a, n, count_compare);
}

