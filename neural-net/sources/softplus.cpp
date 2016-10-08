#include "header.h"

float_t softplus(float_t x)
{
	/* TODO: approximation */

	return static_cast<float_t>(log(1 + exp(x)));
}