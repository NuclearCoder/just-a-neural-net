#include "header.h"

int main(int argc, char** argv)
{
	(void)argc;
	(void)argv;

	/* net is hard-coded for testing purposes */

	Matrix input(2, 1); // random input vector (1; .5)
	input[0][0] = 1.0;
	input[1][0] = -0.5;

	std::vector<uint_t> layers;
	layers.push_back(15);
	layers.push_back(9);
	layers.push_back(13);
	layers.push_back(7);
	layers.push_back(3);

	Network net(2, 1, layers, sigmoid);
	Matrix output(net.compute(input));

	std::cout << output << std::endl;

	system("pause");
	return 0;
}