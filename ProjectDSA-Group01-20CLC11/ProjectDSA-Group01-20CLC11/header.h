#ifndef HEADER_H
#define HEADER_H

//----------LIBRARY----------
#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>
#include <ctype.h> // to differentiate between number and char
#include <string> // because... reasons
#include <cstring>

//----------DEFINITION----------
#define selectionsort 1
#define insertionsort 2
#define bubblesort 3
#define shakersort 4
#define shellsort 5
#define heapsort 6
#define mergesort 7
#define quicksort 8
#define countingsort 9
#define radixsort 10
#define flashsort 11

#define random 0
#define sorted 1
#define reversed 2
#define nearlysorted 3

#define time 1
#define comparison 2
#define both 3

//----------BUBBLE SORT----------
void bubble_sort(int* a, int n);
void bubble_sort_compare(int* a, int n, unsigned long long & count_compare);

//----------SELECTION SORT----------
void selection_sort(int* a, int n);
void selection_sort_compare(int* a, int n, unsigned long long & count_compare);

//----------INSERTION SORT----------
void insertion_sort(int* a, int n);
void insertion_sort_compare(int* a, int n, unsigned long long & count_compare);

//----------SHAKER SORT----------
void shaker_sort(int* a, int n);
void shaker_sort_compare(int* a, int n, unsigned long long & count_compare);

//----------SHELL SORT----------
void shell_sort(int* a, int n);
void shell_sort_compare(int* a, int n, unsigned long long & count_compare);

//----------HEAP SORT----------
void heapify_sort(int* a, int n, int i);
void heap_sort(int* a, int n);
void heapify_sort_compare(int* a, int n, int i, unsigned long long & count_compare);
void heap_sort_compare(int* a, int n, unsigned long long & count_compare);

//----------MERGE SORT----------
void merge_sort(int* a, int left, int right);
void merge(int* a, int left, int mid, int right);
void merge_sort_compare(int* a, int left, int right, unsigned long long & count_compare);
void merge_compare(int* a, int left, int mid, int right, unsigned long long & count_compare);

//----------QUICK SORT----------
void quick_sort(int* a, int left, int right);
void quick_sort_compare(int* a, int left, int right, unsigned long long & count_compare);

//----------COUNTING SORT----------
void counting_sort(int* a, int n);
void counting_sort_compare(int* a, int n, unsigned long long & count_compare);

//----------RADIX SORT----------
void radix_sort(int* a, int n);
void radix_sort_compare(int* a, int n, unsigned long long & count_compare);

//----------FLASH SORT----------
void flash_sort(int* a, int n);
void flash_sort_compare(int* a, int n, unsigned long long & count_compare);

//----------DATA GENERATOR----------
template <class T>
void HoanVi(T& a, T& b);
void GenerateRandomData(int a[], int n); 
void GenerateSortedData(int a[], int n);
void GenerateReverseData(int a[], int n);
void GenerateNearlySortedData(int a[], int n);
void GenerateData(int a[], int n, int dataType);

//----------FILE----------
void outputFile(std::string, int*, int);
int* inputFile(std::string filename, int n);
int inputSize(std::string filename);
int* copyFile(int* a, int n);

//----------RUNTIME & COMPARISON----------
int selectionSortRuntime(int* a, int n);
int insertionSortRuntime(int* a, int n);
int bubbleSortRuntime(int* a, int n);
int shakerSortRuntime(int* a, int n);
int shellSortRuntime(int* a, int n);
int heapSortRuntime(int* a, int n);
int mergeSortRuntime(int* a, int left, int right);
int quickSortRuntime(int* a, int left, int right);
int countingSortRuntime(int* a, int n);
int radixSortRuntime(int* a, int n);
int flashSortRuntime(int* a, int n); 
int runTime(int algorithm, int* a, int n);
unsigned long long compCount(int algorithm, int* a, int n);

//----------SUB FUNCTION----------
bool check_number(char* argv);

//----------COMMAND LINE----------
void command_1(char* argv[], int algorithm, int outmode, std::string filename);
void command_2(char* argv[], int algorithm, int size, int order, int outmode);
void command_3(char* argv[], int algorithm, int size, int outmode);
void command_4(char* argv[], int algorithm1, int algorithm2, std::string filename);
void command_5(char* argv[], int algorithm1, int algorithm2, int size, int order, std::string filename);
void check_command(int argc, char* argv[], int& C, int& mode, int& algorithm1, int& algorithm2, int& size, int& order, int& outmode, std::string filename);

#endif // !HEADER_H

