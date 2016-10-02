#include "header.h"

int main(int argc, char** argv)
{
	(void)argc;
	(void)argv;

	// init the RNG
	srand(static_cast<uint_t>(time(nullptr)));

	/* net is hard-coded for testing purposes */

	Matrix input(2, 1); // random input vector (1; .5)
	input[0][0] = 1.0;
	input[1][0] = 0.5;

	std::vector<Matrix> layers;
	layers.push_back(Matrix(3, 2));

	Network net(2, 1, layers, sigmoid);
	Matrix output(net.compute(input));

	std::cout << output << std::endl;

	system("pause");
	return 0;
}