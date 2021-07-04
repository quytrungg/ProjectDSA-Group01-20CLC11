#include "header.h"

void check_input(int argc, char* argv[]) {
	Command a;
	a.mode = argv[1];
	a.algorithm1 = argv[2];
	a.algorithm2 = argv[3];
	a.filename = argv[3];
	a.size = atoi(argv[3]);
	a.order = atoi(argv[4]);
	a.outmode = argv[5];
}

void command_1(Command C, int* a, int n) {
	inputFile(C.filename, a, n);
	std::cout << "ALGORITHM MODE\n";
	std::cout << "Algorithm: " << C.algorithm1 << "\n";
	std::cout << "Input file: " << C.filename << "\n";
	std::cout << "Input size: " << n << "\n";
	std::cout << "-------------------------\n";
	if (C.outmode.compare("-time") == 0) std::cout << "Running time: " << runTime(C.algorithm1, a, n);
	else if (C.outmode.compare("-comp") == 0) std::cout << "Comparisons: " << compCount(C.algorithm1, a, n);
	else {
		std::cout << "Running time: " << runTime(C.algorithm1, a, n) << "\n";
		std::cout << "Comparisons: " << compCount(C.algorithm1, a, n);
	}
}

void command_2(Command C, int* a, int n) {
	std::cout << "ALGORITHM MODE\n";
	std::cout << "Algorithm: " << C.algorithm1 << "\n";
	std::cout << "Input size: " << C.size << "\n";
	std::cout << "Input order: " << C.order << "\n";
	std::cout << "-------------------------\n";
	GenerateData(a, n, C.order);
	if (C.outmode.compare("-time") == 0) std::cout << "Running time: " << runTime(C.algorithm1, a, n);
	else if (C.outmode.compare("-comp") == 0) std::cout << "Comparisons: " << compCount(C.algorithm1, a, n);
	else {
		std::cout << "Running time: " << runTime(C.algorithm1, a, n) << "\n";
		std::cout << "Comparisons: " << compCount(C.algorithm1, a, n);
	}
}

void command_3(Command C, int* a, int n) {
	std::cout << "ALGORITHM MODE";
	std::cout << "Algorithm: " << C.algorithm1 << "\n";
	std::cout << "Input size: " << C.size << "\n\n";
	std::cout << "Input order: Randomize\n";
	std::cout << "-------------------------\n";
	GenerateData(a, n, 0);
	std::cout << "Running time (If required): " << runTime(C.algorithm1, a, n) << "\n";
	std::cout << "Comparisons (If required): " << compCount(C.algorithm1, a, n) << "\n\n";
	std::cout << "Input order: Nearly Sorted\n";
	std::cout << "-------------------------\n";
	GenerateData(a, n, 3);
	std::cout << "Running time (If required): " << runTime(C.algorithm1, a, n) << "\n";
	std::cout << "Comparisons (If required): " << compCount(C.algorithm1, a, n) << "\n\n";
	std::cout << "Input order: Sorted\n";
	std::cout << "-------------------------\n";
	GenerateData(a, n, 1);
	std::cout << "Running time (If required): " << runTime(C.algorithm1, a, n) << "\n";
	std::cout << "Comparisons (If required): " << compCount(C.algorithm1, a, n) << "\n\n";
	std::cout << "Input order: Reversed\n";
	std::cout << "-------------------------\n";
	GenerateData(a, n, 2);
	std::cout << "Running time (If required): " << runTime(C.algorithm1, a, n) << "\n";
	std::cout << "Comparisons (If required): " << compCount(C.algorithm1, a, n) << "\n\n";
}

void command_4(Command C, int* a, int n) {
	std::cout << "COMPARE MODE\n";
	std::cout << "Algorithm: " << C.algorithm1 << " | " << C.algorithm2 << "\n";

}

void command_5(Command C) {
	int* a, n;
}
