#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>
#include <ctype.h> // to differentiate between number and char
#include <string> // because... reasons

void algorithmMode(int argc, char* argv[], int*& a);
void time_count(char* sortType, char* outputPara, int* a, int n);

//Bubble sort
void bubble_sort(int* a, int n);
void bubble_sort_compare(int* a, int n, unsigned long long & count_compare);

//Selection sort
void selection_sort(int* a, int n);
void selection_sort_compare(int* a, int n, unsigned long long & count_compare);

//Insertion sort
void insertion_sort(int* a, int n);
void insertion_sort_compare(int* a, int n, unsigned long long & count_compare);

//Shaker sort
void shaker_sort(int* a, int n);
void shaker_sort_compare(int* a, int n, unsigned long long & count_compare);

//Shell sort
void shell_sort(int* a, int n);
void shell_sort_comparision(int* a, int n, unsigned long long & count_compare);

//Heap sort
void heapify_sort(int* a, int n, int i);
void heap_sort(int* a, int n);
void heapify_sort_compare(int* a, int n, int i, unsigned long long & count_compare);
void heap_sort_compare(int* a, int n, unsigned long long & count_compare);

//Merge sort
void merge_sort(int* a, int left, int right);
void merge(int* a, int left, int mid, int right);
void merge_sort_compare(int* a, int left, int right, unsigned long long & count_compare);
void merge_compare(int* a, int left, int mid, int right, unsigned long long & count_compare);

//Quick sort
void quick_sort(int* a, int left, int right);
void quick_sort_compare(int* a, int left, int right, unsigned long long & count_compare);

//Counting sort
void counting_sort(int* a, int n);
void counting_sort_compare(int* a, int n, unsigned long long & count_compare);

//Radix sort
void radix_sort(int* a, int n);
void radix_sort_compare(int* a, int n, unsigned long long & count_compare);

//Flash sort
void flash_sort(int* a, int n);
void flash_sort_compare(int* a, int n, unsigned long long & count_compare);

void check_input(int argc, char* argv[]);

//Ham cua thay Thong
template <class T>
void HoanVi(T& a, T& b);
void GenerateRandomData(int a[], int n); 
void GenerateSortedData(int a[], int n);
void GenerateReverseData(int a[], int n);
void GenerateNearlySortedData(int a[], int n);
void GenerateData(int a[], int n, int dataType);

//Ham cua Quoc Bao
void outputFile(const char*, int*, int);
void outputFile4(const char* filename, int* a, int n);

#endif // !HEADER_H

