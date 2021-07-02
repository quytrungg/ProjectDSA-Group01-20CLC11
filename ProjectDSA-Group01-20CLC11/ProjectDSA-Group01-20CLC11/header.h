#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>
#include <iomanip>
#include <ctype.h> // to differentiate between number and char
#include <string> // because... reasons

void algorithmMode(int argc, char* argv[], int a[]);

void swap_element(int a, int b);
void time_count(char* sortType, char* outputPara, int* a, int n, int extra = 0);

void bubble_sort(int* a, int n);
void bubble_sort_compare(int* a, int n, int& count_compare);

void selection_sort(int* a, int n);
void selection_sort_compare(int* a, int n, int& count_compare);

void insertion_sort(int* a, int n);
void insertion_sort_compare(int* a, int n, int& count_compare);

void shaker_sort(int* a, int n);
void shaker_sort_compare(int* a, int n, int& count_compare);

void shell_sort(int* a, int n);
void shell_sort_comparision(int* a, int n, int& count_compare);

void heapify_sort(int* a, int n, int i);
void heap_sort(int* a, int n);
void heapify_sort_compare(int* a, int n, int i, int& count_compare);
void heap_sort_compare(int* a, int n, int& count_compare);

void merge_sort(int* a, int left, int right);
void merge(int* a, int left, int mid, int right);
void merge_sort_compare(int* a, int left, int right, int& count_compare);
void merge_compare(int* a, int left, int mid, int right, int& count_compare);

void quick_sort(int* a, int left, int right);
void quick_sort_compare(int* a, int left, int right, int& count_compare);

void counting_sort(int* a, int n);
void counting_sort_compare(int* a, int n, int& count_compare);

void radix_sort(int* a, int n);
void radix_sort_compare(int* a, int n, int& count_compare);

void check_input(int argc, char* argv[]);
void main_fake();

template <class T>
void HoanVi(T& a, T& b);
void GenerateRandomData(int a[], int n); 
void GenerateSortedData(int a[], int n);
void GenerateReverseData(int a[], int n);
void GenerateNearlySortedData(int a[], int n);
void GenerateData(int a[], int n, int dataType);

#endif // !HEADER_H

