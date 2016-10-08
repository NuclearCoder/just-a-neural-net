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

	std::vector<uint_t> layers = { 3, 2 };

	Network net(2, 1, layers, softplus, softplus_diff);

	/* let's test on finding slope */


	Matrix input(2,1); // (1, 20) and (2, 40)
	input[0][0] = 20;
	input[1][0] = 40;
	
	// should have a slope of 20
	Matrix expected(1, 1);
	expected[0][0] = 20;

	
	net.train(input, expected);

	
	std::cout << net.compute(input) << std::endl;


	system("pause");
	return 0;
}
