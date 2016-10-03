#pragma once

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

	const floatfun_t _activation;

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
	
};