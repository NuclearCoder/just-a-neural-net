#include "header.h"

float_t random_gaussian(float_t mean, float_t stddev)
{
	// this uses Box-Muller transform and polar coordinates
	// -> avoid exp and avoid trig

	static std::default_random_engine rng(static_cast<uint_t>(time(nullptr)));
	static std::uniform_real_distribution<float_t> uniform(0.0, 1.0);

	static float_t y1, y2;
	static bool generate;

	float_t x1, x2, w;
	
	generate = !generate;
	if (!generate)
		return y2 * stddev + mean;

	do
	{
		// polar transformation
		x1 = static_cast<float_t>(2.0 * uniform(rng) - 1.0);
		x2 = static_cast<float_t>(2.0 * uniform(rng) - 1.0);
		w = x1 * x1 + x2 * x2;
	} while (w >= 1.0);

	// transform back to cartesian
	w = static_cast<float_t>(sqrt((-2.0 * log(w)) / w));
	y1 = x1 * w;
	y2 = x2 * w;

	return y1 * stddev + mean;
}
