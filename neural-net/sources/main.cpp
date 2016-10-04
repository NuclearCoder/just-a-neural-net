#include "header.h"

std::ofstream gDebugStream("neural-net-debug.log", std::ios_base::out);

std::ostream& debug()
{
	return gDebugStream;
}

int main(int argc, char** argv)
{
	(void)argc;
	(void)argv;

	/* net is hard-coded for testing purposes */

	Matrix input(2, 1); // random input vector (1; .5)
	input[0][0] = 3.1;
	input[1][0] = -0.9;

	std::vector<uint_t> layers = { 3 };

	Network net(2, 1, layers, sigmoid);
	Matrix output(net.compute(input));

	std::cout << output << std::endl;

	return 0;
}