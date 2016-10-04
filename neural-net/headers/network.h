#pragma once

std::ostream& debug();

class Network
{
public:
	Network(const uint_t nbInputs, const uint_t nbOutputs,
			const std::vector<uint_t> layers, const floatfun_t activation);

	/* Passes the input through the network. */
	Matrix compute(const Matrix& input);

private:
	float_t random_weight() const;

	const uint_t _nbInputs; 
	const uint_t _nbOutputs;
	const uint_t _nbLayers; // the topology of the network will be fixed during the lifetime

	const floatfun_t _actFun;

	/* For each layer, the matrix of weights
	 * Each matrix is size (l_[i+1], l_[i])
	 */
	std::vector<Matrix> _layers;

	/* For each layer, the last output that
	 * passed through.
	 * Each output vector is a 
	 * matrix whose size is (l_[i], 1)
	 * The 0-th elt is the input vector
	 * The n-th elt is the output vector
	 */
	std::vector<Matrix> _outputs;

	/* For each layer, the last activations. (before the activation function is applied)
	 * Each output vector is a 
	 * matrix whose size is (l_[i], 1)
	 * The 0-th elt is the input vector
	 * The n-th elt is the output activation
	 */
	std::vector<Matrix> _activations;
	
};


/*

Notations:
 g is the activation function
 g' is its derivative
 t,y are the expected,computed output
 h is the list of activation vectors
 e is the list of error vectors
 A is the inertia factor [0.0, 1.0[
 B is the learning rate (small magnitude & less than 1.0)

> First, calculate the error on the output
e[n + 1][j] = g'( h[n + 1][j] ) * ||t[j] - y[j]||

> Propagate back the error
e[k - 1][j] = g'( h[k - 1][j] ) * Sum_i( w[i][j] * e[k][i] )

> Change the weights based on the error
w[k][i, j] = A * w[k][i, j] + B * e[k][i] * x[n - 1][j]

Notes:
 we should change the weights as we calculate the errors

*/