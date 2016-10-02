#include "header.h"

inline float_t randf()
{
	return static_cast<float_t>(rand()) / static_cast<float_t>(RAND_MAX);
}

float_t random_gaussian(float_t dev, float_t mean)
{
	// this uses Box-Muller transform and polar coordinates
	// -> avoid exp and avoid trig

	static float_t y1, y2;
	static bool generate;

	float_t x1, x2, w;
	
	generate = !generate;
	if (!generate)
		return y2 * dev + mean;

	do
	{
		// polar transformation
		x1 = static_cast<float_t>(2.0 * randf() - 1.0);
		x2 = static_cast<float_t>(2.0 * randf() - 1.0);
		w = x1 * x1 + x2 * x2;
	} while (w >= 1.0);

	// transform back to cartesian
	w = static_cast<float_t>(sqrt((-2.0 * log(w)) / w));
	y1 = x1 * w;
	y2 = x2 * w;

	return y1 * dev + mean;
}
