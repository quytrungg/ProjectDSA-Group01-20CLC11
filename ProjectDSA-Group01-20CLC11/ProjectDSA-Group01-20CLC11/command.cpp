#include "header.h"

//Check if command is a number
bool check_number(char* argv) {
	for (int i = 0; i < strlen(argv); i++) {
		if (argv[i] < '0' || argv[i] > '9') {
			return false;
		}
	}
	return true;
}

//Command 1
void command_1(char* argv[], int algorithm, int outmode, std::string filename) {
	int n = 0;
	int* a = inputFile(filename, n);
	int* b = copyFile(a, n);
	std::cout << "ALGORITHM MODE\n";
	std::cout << "Algorithm: " << argv[2] << "\n";
	std::cout << "Input file: " << filename << "\n";
	std::cout << "Input size: " << n << "\n";
	std::cout << "-------------------------\n";
	if (outmode == 1) std::cout << "Running time: " << runTime(algorithm, a, n);
	else if (outmode == 2) std::cout << "Comparisons: " << compCount(algorithm, a, n);
	else {
		std::cout << "Running time: " << runTime(algorithm, a, n) << "\n";
		std::cout << "Comparisons: " << compCount(algorithm, b, n);
	}
	outputFile("output.txt", a, n);
}

//Command 2
void command_2(char* argv[], int algorithm, int size, int order, int outmode) {
	int n = size;
	int* a = new int[n];
	GenerateData(a, n, order);
	outputFile("input.txt", a, n);
	int* b = copyFile(a, n);
	std::cout << "ALGORITHM MODE\n";
	std::cout << "Algorithm: " << argv[2] << "\n";
	std::cout << "Input size: " << size << "\n";
	std::cout << "Input order: " << "\n";
	std::cout << "-------------------------\n";
	if (outmode == 1) std::cout << "Running time: " << runTime(algorithm, a, n);
	else if (outmode == 2) std::cout << "Comparisons: " << compCount(algorithm, a, n);
	else {
		std::cout << "Running time: " << runTime(algorithm, a, n) << "\n";
		std::cout << "Comparisons: " << compCount(algorithm, b, n);
	}
	outputFile("output.txt", a, n);
}

//Command 3
void command_3(char* argv[], int algorithm, int size, int outmode) {
	int n = size;
	int* a = new int[n];
	if (outmode == 1) {
		std::cout << "ALGORITHM MODE\n";
		std::cout << "Algorithm: " << algorithm << "\n";
		std::cout << "Input size: " << size << "\n\n";
		std::cout << "Input order: Randomize\n";
		std::cout << "-------------------------\n";
		GenerateData(a, n, 0);
		outputFile("input_1.txt", a, n);
		std::cout << "Running time (If required): " << runTime(algorithm, a, n) << "\n\n";
		std::cout << "Input order: Nearly Sorted\n";
		std::cout << "-------------------------\n";
		GenerateData(a, n, 3);
		outputFile("input_2.txt", a, n);
		std::cout << "Running time (If required): " << runTime(algorithm, a, n) << "\n\n";
		std::cout << "Input order: Sorted\n";
		std::cout << "-------------------------\n";
		GenerateData(a, n, 1);
		outputFile("input_3.txt", a, n);
		std::cout << "Running time (If required): " << runTime(algorithm, a, n) << "\n\n";
		std::cout << "Input order: Reversed\n";
		std::cout << "-------------------------\n";
		GenerateData(a, n, 2);
		outputFile("input_4.txt", a, n);
		std::cout << "Running time (If required): " << runTime(algorithm, a, n) << "\n";
	}
	else if (outmode == 2) {
		std::cout << "ALGORITHM MODE\n";
		std::cout << "Algorithm: " << algorithm << "\n";
		std::cout << "Input size: " << size << "\n\n";
		std::cout << "Input order: Randomize\n";
		std::cout << "-------------------------\n";
		GenerateData(a, n, 0);
		outputFile("input_1.txt", a, n);
		std::cout << "Comparisons (If required): " << compCount(algorithm, a, n) << "\n\n";
		std::cout << "Input order: Nearly Sorted\n";
		std::cout << "-------------------------\n";
		GenerateData(a, n, 3);
		outputFile("input_2.txt", a, n);
		std::cout << "Comparisons (If required): " << compCount(algorithm, a, n) << "\n\n";
		std::cout << "Input order: Sorted\n";
		std::cout << "-------------------------\n";
		GenerateData(a, n, 1);
		outputFile("input_3.txt", a, n);
		std::cout << "Comparisons (If required): " << compCount(algorithm, a, n) << "\n\n";
		std::cout << "Input order: Reversed\n";
		std::cout << "-------------------------\n";
		GenerateData(a, n, 2);
		outputFile("input_4.txt", a, n);
		std::cout << "Comparisons (If required): " << compCount(algorithm, a, n) << "\n";

	}
	else {
		std::cout << "ALGORITHM MODE\n";
		std::cout << "Algorithm: " << algorithm << "\n";
		std::cout << "Input size: " << size << "\n\n";
		std::cout << "Input order: Randomize\n";
		std::cout << "-------------------------\n";
		GenerateData(a, n, 0);
		outputFile("input_1.txt", a, n);
		std::cout << "Running time (If required): " << runTime(algorithm, a, n) << "\n";
		std::cout << "Comparisons (If required): " << compCount(algorithm, a, n) << "\n\n";
		std::cout << "Input order: Nearly Sorted\n";
		std::cout << "-------------------------\n";
		GenerateData(a, n, 3);
		outputFile("input_2.txt", a, n);
		std::cout << "Running time (If required): " << runTime(algorithm, a, n) << "\n";
		std::cout << "Comparisons (If required): " << compCount(algorithm, a, n) << "\n\n";
		std::cout << "Input order: Sorted\n";
		std::cout << "-------------------------\n";
		GenerateData(a, n, 1);
		outputFile("input_3.txt", a, n);
		std::cout << "Running time (If required): " << runTime(algorithm, a, n) << "\n";
		std::cout << "Comparisons (If required): " << compCount(algorithm, a, n) << "\n\n";
		std::cout << "Input order: Reversed\n";
		std::cout << "-------------------------\n";
		GenerateData(a, n, 2);
		outputFile("input_4.txt", a, n);
		std::cout << "Running time (If required): " << runTime(algorithm, a, n) << "\n";
		std::cout << "Comparisons (If required): " << compCount(algorithm, a, n) << "\n";
	}
}

//Command 4
void command_4(char* argv[], int algorithm1, int algorithm2, std::string filename) {
	int n = 0;
	int* a = inputFile(filename, n);
	int* b = copyFile(a, n);
	int* c = copyFile(a, n);
	int* d = copyFile(a, n);
	std::cout << "COMPARE MODE\n";
	std::cout << "Algorithm: " << algorithm1 << " | " << algorithm2 << "\n";
	std::cout << "Input file: " << filename << "\n";
	std::cout << "Input size: " << n << "\n";
	std::cout << "-------------------------\n";
	std::cout << "Running time: " << runTime(algorithm1, a, n) << " | " << runTime(algorithm2, b, n) << "\n";
	std::cout << "Comparisons: " << compCount(algorithm1, c, n) << " | " << compCount(algorithm2, d, n) << "\n";
}

//Command 5
void command_5(char* argv[], int algorithm1, int algorithm2, int size, int order, std::string filename) {
	int n = size;
	int* a = new int[n];
	GenerateData(a, n, order);
	outputFile("input.txt", a, n);
	int* b = copyFile(a, n);
	int* c = copyFile(a, n);
	int* d = copyFile(a, n);
	std::cout << "COMPARE MODE\n";
	std::cout << "Algorithm: " << argv[2] << " | " << argv[3] << "\n";
	std::cout << "Input size: " << size << "\n";
	std::cout << "Input order: " << order << "\n";
	std::cout << "-------------------------\n";
	std::cout << "Running time: " << runTime(algorithm1, a, n) << " | " << runTime(algorithm2, b, n) << "\n";
	std::cout << "Comparisons: " << compCount(algorithm1, c, n) << " | " << compCount(algorithm2, d, n) << "\n";
}

//Check command
void check_command(int argc, char* argv[], int& C, int& mode, int& algorithm1, int& algorithm2, int& size, int& order, int& outmode, std::string filename) {
	if (strcmp(argv[2], "selection-sort") == 0) { algorithm1 = 1; }
	else if (strcmp(argv[2], "insertion-sort") == 0) { algorithm2 = 2; }
	else if (strcmp(argv[2], "bubble-sort") == 0) { algorithm2 = 3; }
	else if (strcmp(argv[2], "shaker-sort") == 0) { algorithm2 = 4; }
	else if (strcmp(argv[2], "shell-sort") == 0) { algorithm2 = 5; }
	else if (strcmp(argv[2], "heap-sort") == 0) { algorithm2 = 6; }
	else if (strcmp(argv[2], "merge-sort") == 0) { algorithm2 = 7; }
	else if (strcmp(argv[2], "quick-sort") == 0) { algorithm2 = 8; }
	else if (strcmp(argv[2], "counting-sort") == 0) { algorithm2 = 9; }
	else if (strcmp(argv[2], "radix-sort") == 0) { algorithm2 = 10; }
	else if (strcmp(argv[2], "flash-sort") == 0) { algorithm2 = 11; }
	if (strcmp(argv[1], "-a") == 0) {
		mode = 1;
		if (argc == 6) {
			size = atoi(argv[3]);
			if (strcmp(argv[4], "-rand") == 0) { order = 0; }
			else if (strcmp(argv[4], "-sorted") == 0) { order = 1; }
			else if (strcmp(argv[4], "-rev") == 0) { order = 2; }
			else if (strcmp(argv[4], "-nsorted") == 0) { order = 3; }
			else if (strcmp(argv[5], "-time") == 0) { outmode = 1; }
			else if (strcmp(argv[5], "-comp") == 0) { outmode = 2; }
			else if (strcmp(argv[5], "-both") == 0) { outmode = 3; }
			C = 2;
		}
		else if (check_number(argv[3])) {
			size = atoi(argv[3]);
			if (strcmp(argv[4], "-time") == 0) { outmode = 1; }
			else if (strcmp(argv[4], "-comp") == 0) { outmode = 2; }
			else if (strcmp(argv[4], "-both") == 0) { outmode = 3; }
			C = 3;
		}
		else {
			filename = argv[3];
			if (strcmp(argv[4], "-time") == 0) { outmode = 1; }
			else if (strcmp(argv[4], "-comp") == 0) { outmode = 2; }
			else if (strcmp(argv[4], "-both") == 0) { outmode = 3; }
			C = 1;
		}
	}
	else if (strcmp(argv[1], "-c") == 0) {
		mode = 2;
		if (strcmp(argv[3], "selection-sort") == 0) { algorithm2 = 1; }
		else if (strcmp(argv[3], "insertion-sort") == 0) { algorithm2 = 2; }
		else if (strcmp(argv[3], "bubble-sort") == 0) { algorithm2 = 3; }
		else if (strcmp(argv[3], "shaker-sort") == 0) { algorithm2 = 4; }
		else if (strcmp(argv[3], "shell-sort") == 0) { algorithm2 = 5; }
		else if (strcmp(argv[3], "heap-sort") == 0) { algorithm2 = 6; }
		else if (strcmp(argv[3], "merge-sort") == 0) { algorithm2 = 7; }
		else if (strcmp(argv[3], "quick-sort") == 0) { algorithm2 = 8; }
		else if (strcmp(argv[3], "counting-sort") == 0) { algorithm2 = 9; }
		else if (strcmp(argv[3], "radix-sort") == 0) { algorithm2 = 10; }
		else if (strcmp(argv[3], "flash-sort") == 0) { algorithm2 = 11; }
		if (argc == 5) {
			filename = argv[4];
			C = 4;
		}
		else {
			size = atoi(argv[4]);
			if (strcmp(argv[5], "-rand") == 0) { order = 0; }
			else if (strcmp(argv[5], "-sorted") == 0) { order = 1; }
			else if (strcmp(argv[5], "-rev") == 0) { order = 2; }
			else if (strcmp(argv[5], "-nsorted") == 0) { order = 3; }
			C = 5;
		}
	}
	if (filename == ""){
		filename = "\0";
	}
}