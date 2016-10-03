#include "header.h"

float_t sigmoid(float_t x)
{
	double y = 1.0 / (2.0 - x * (1.0 + x / 2.0));
	return static_cast<float_t>(y);
}

float_t sigmoid_diff(float_t x)
{
	float_t y = sigmoid(x);
	return y * (1 - y);
} 