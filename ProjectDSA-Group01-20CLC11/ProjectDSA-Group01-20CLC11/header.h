#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>

void swap_element(int a, int b);

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


template <class T>
void HoanVi(T& a, T& b);
void GenerateRandomData(int a[], int n); 
void GenerateSortedData(int a[], int n);
void GenerateReverseData(int a[], int n);
void GenerateNearlySortedData(int a[], int n);
void GenerateData(int a[], int n, int dataType);

#endif // !HEADER_H

