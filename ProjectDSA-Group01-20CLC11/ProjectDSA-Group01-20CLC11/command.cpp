#include "header.h"

//Get command info
Command check_input(int argc, char* argv[]) {
	Command C;
	C.mode = argv[1];
	C.algorithm1 = argv[2];
	C.algorithm2 = argv[3];
	C.filename = argv[3];
	C.size = atoi(argv[3]);
	C.order = argv[4];
	C.outmode = argv[5];
	return C;
}

//Check if command is a number
bool check_number(char* argv) {
	for (int i = 0; i < strlen(argv); i++) {
		if (argv[i] >= 'A' && argv[i] <= 'z') {
			return false;
		}
	}
	return true;
}

//Command 1
void command_1(Command C, int* a, int n) {
	inputFile(C.filename, a, n);
	int* b = copyFile(a, n);
	std::cout << "ALGORITHM MODE\n";
	std::cout << "Algorithm: " << C.algorithm1 << "\n";
	std::cout << "Input file: " << C.filename << "\n";
	std::cout << "Input size: " << n << "\n";
	std::cout << "-------------------------\n";
	if (C.outmode.compare("-time") == 0) std::cout << "Running time: " << runTime(C.algorithm1, a, n);
	else if (C.outmode.compare("-comp") == 0) std::cout << "Comparisons: " << compCount(C.algorithm1, a, n);
	else {
		std::cout << "Running time: " << runTime(C.algorithm1, a, n) << "\n";
		std::cout << "Comparisons: " << compCount(C.algorithm1, b, n);
	}
	outputFile("output.txt", a, n);
}

//Command 2
void command_2(Command C, int* a, int n) {
	std::cout << "ALGORITHM MODE\n";
	std::cout << "Algorithm: " << C.algorithm1 << "\n";
	std::cout << "Input size: " << C.size << "\n";
	std::cout << "Input order: " << C.order << "\n";
	std::cout << "-------------------------\n";
	if (C.order.compare("-rand") == 0) GenerateData(a, n, 0);
	else if (C.order.compare("-nsorted") == 0) GenerateData(a, n, 3);
	else if (C.order.compare("-sorted") == 0) GenerateData(a, n, 1);
	else if (C.order.compare("-rev") == 0) GenerateData(a, n, 2);
	int* b = copyFile(a, n);
	outputFile("input.txt", a, n);
	if (C.outmode.compare("-time") == 0) std::cout << "Running time: " << runTime(C.algorithm1, a, n);
	else if (C.outmode.compare("-comp") == 0) std::cout << "Comparisons: " << compCount(C.algorithm1, a, n);
	else {
		std::cout << "Running time: " << runTime(C.algorithm1, a, n) << "\n";
		std::cout << "Comparisons: " << compCount(C.algorithm1, b, n);
	}
	outputFile("output.txt", a, n);
}

//Command 3
void command_3(Command C, int* a, int n) {
	if (C.outmode.compare("-time") == 0) {
		std::cout << "ALGORITHM MODE";
		std::cout << "Algorithm: " << C.algorithm1 << "\n";
		std::cout << "Input size: " << C.size << "\n\n";
		std::cout << "Input order: Randomize\n";
		std::cout << "-------------------------\n";
		GenerateData(a, n, 0);
		outputFile("intput_1.txt", a, n);
		std::cout << "Running time (If required): " << runTime(C.algorithm1, a, n) << "\n\n";
		std::cout << "Input order: Nearly Sorted\n";
		std::cout << "-------------------------\n";
		GenerateData(a, n, 3);
		outputFile("input_2.txt", a, n);
		std::cout << "Running time (If required): " << runTime(C.algorithm1, a, n) << "\n\n";
		std::cout << "Input order: Sorted\n";
		std::cout << "-------------------------\n";
		GenerateData(a, n, 1);
		outputFile("input_3.txt", a, n);
		std::cout << "Running time (If required): " << runTime(C.algorithm1, a, n) << "\n\n";
		std::cout << "Input order: Reversed\n";
		std::cout << "-------------------------\n";
		GenerateData(a, n, 2);
		outputFile("input_4.txt", a, n);
		std::cout << "Running time (If required): " << runTime(C.algorithm1, a, n) << "\n";
	}
	else if (C.outmode.compare("-comp") == 0) {
		std::cout << "ALGORITHM MODE";
		std::cout << "Algorithm: " << C.algorithm1 << "\n";
		std::cout << "Input size: " << C.size << "\n\n";
		std::cout << "Input order: Randomize\n";
		std::cout << "-------------------------\n";
		GenerateData(a, n, 0);
		outputFile("intput_1.txt", a, n);
		std::cout << "Comparisons (If required): " << compCount(C.algorithm1, a, n) << "\n\n";
		std::cout << "Input order: Nearly Sorted\n";
		std::cout << "-------------------------\n";
		GenerateData(a, n, 3);
		outputFile("input_2.txt", a, n);
		std::cout << "Comparisons (If required): " << compCount(C.algorithm1, a, n) << "\n\n";
		std::cout << "Input order: Sorted\n";
		std::cout << "-------------------------\n";
		GenerateData(a, n, 1);
		outputFile("input_3.txt", a, n);
		std::cout << "Comparisons (If required): " << compCount(C.algorithm1, a, n) << "\n\n";
		std::cout << "Input order: Reversed\n";
		std::cout << "-------------------------\n";
		GenerateData(a, n, 2);
		outputFile("input_4.txt", a, n);
		std::cout << "Comparisons (If required): " << compCount(C.algorithm1, a, n) << "\n";

	}
	else {
		std::cout << "ALGORITHM MODE";
		std::cout << "Algorithm: " << C.algorithm1 << "\n";
		std::cout << "Input size: " << C.size << "\n\n";
		std::cout << "Input order: Randomize\n";
		std::cout << "-------------------------\n";
		GenerateData(a, n, 0);
		outputFile("input_1.txt", a, n);
		std::cout << "Running time (If required): " << runTime(C.algorithm1, a, n) << "\n";
		std::cout << "Comparisons (If required): " << compCount(C.algorithm1, a, n) << "\n\n";
		std::cout << "Input order: Nearly Sorted\n";
		std::cout << "-------------------------\n";
		GenerateData(a, n, 3);
		outputFile("input_2.txt", a, n);
		std::cout << "Running time (If required): " << runTime(C.algorithm1, a, n) << "\n";
		std::cout << "Comparisons (If required): " << compCount(C.algorithm1, a, n) << "\n\n";
		std::cout << "Input order: Sorted\n";
		std::cout << "-------------------------\n";
		GenerateData(a, n, 1);
		outputFile("input_3.txt", a, n);
		std::cout << "Running time (If required): " << runTime(C.algorithm1, a, n) << "\n";
		std::cout << "Comparisons (If required): " << compCount(C.algorithm1, a, n) << "\n\n";
		std::cout << "Input order: Reversed\n";
		std::cout << "-------------------------\n";
		GenerateData(a, n, 2);
		outputFile("input_4.txt", a, n);
		std::cout << "Running time (If required): " << runTime(C.algorithm1, a, n) << "\n";
		std::cout << "Comparisons (If required): " << compCount(C.algorithm1, a, n) << "\n";
	}
}

//Command 4
void command_4(Command C, int* a, int n) {
	inputFile(C.filename, a, n);
	int* b = copyFile(a, n);
	int* c = copyFile(a, n);
	int* d = copyFile(a, n);
	std::cout << "COMPARE MODE\n";
	std::cout << "Algorithm: " << C.algorithm1 << " | " << C.algorithm2 << "\n";
	std::cout << "Input file: " << C.filename << "\n";
	std::cout << "Input size: " << n << "\n";
	std::cout << "-------------------------\n";
	std::cout << "Running time: " << runTime(C.algorithm1, a, n) << " | " << runTime(C.algorithm2, b, n) << "\n";
	std::cout << "Comparisons: " << compCount(C.algorithm1, c, n) << " | " << compCount(C.algorithm2, d, n) << "\n";
}

//Command 5
void command_5(Command C, int* a, int n) {
	std::cout << "COMPARE MODE\n";
	std::cout << "Algorithm: " << C.algorithm1 << " | " << C.algorithm2 << "\n";
	std::cout << "Input size: " << C.size << "\n";
	std::cout << "Input order: " << C.order << "\n";
	std::cout << "-------------------------\n";
	if (C.order.compare("-rand") == 0) GenerateData(a, n, 0);
	else if (C.order.compare("-nsorted") == 0) GenerateData(a, n, 3);
	else if (C.order.compare("-sorted") == 0) GenerateData(a, n, 1);
	else if (C.order.compare("-rev") == 0) GenerateData(a, n, 2);
	int* b = copyFile(a, n);
	int* c = copyFile(a, n);
	int* d = copyFile(a, n);
	outputFile("input.txt", a, n);
	std::cout << "Running time: " << runTime(C.algorithm1, a, n) << " | " << runTime(C.algorithm2, b, n) << "\n";
	std::cout << "Comparisons: " << compCount(C.algorithm1, c, n) << " | " << compCount(C.algorithm2, d, n) << "\n";
}

//Command
void command(Command C, int argc, char* argv[], int* a, int n) {
	C = check_input(argc, argv);
	if (strcmp(argv[1], "-a") == 0 && !check_number(argv[3])) {
		C.outmode = argv[4];
		command_1(C, a, n);
	}
	else if (strcmp(argv[1], "-a") == 0 && check_number(argv[3])) {
		command_2(C, a, n);
	}
	else if (strcmp(argv[1], "-a") == 0 && (argv[4] == "-temp" || argv[4] == "-comp" || argv[4] == "-both")) {
		C.outmode = argv[4];
		command_3(C, a, n);
	}
	else if (strcmp(argv[1], "-c") == 0 && !check_number(argv[4])) {
		C.filename = argv[4];
		command_4(C, a, n);
	}
	else if (strcmp(argv[1], "-c") == 0 && check_number(argv[4])) {
		C.size = atoi(argv[4]);
		C.order = argv[5];
		command_5(C, a, n);
	}
	else return;
}
