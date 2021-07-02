#include "header.h"

int main(int argc, char* argv[]) {
	int* a;
	if (argv[1] == "-a")
	{
		algorithmMode(argc, argv, a);
	}
	return 0;
}