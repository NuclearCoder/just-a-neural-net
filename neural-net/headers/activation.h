#pragma once

/* Sigmoid */

float_t sigmoid(float_t x);
float_t sigmoid_diff(float_t x);


/* Softplus */

float_t softplus(float_t x);
inline float_t softplus_diff(float_t x)
{
	return sigmoid(x);
}