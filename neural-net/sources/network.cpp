#include "header.h"

// NOTE: most methods will throw range_error if there are no layers,
//		too lazy to do a custom check

Network::Network(const uint_t nbInputs, const uint_t nbOutputs,
					const std::vector<Matrix> layers, const floatfun_t activation)
	: _nbInputs(nbInputs), _nbOutputs(nbOutputs), _nbLayers(layers.size()),
		_layers(layers), _activation(activation)
{
	/* First, create the output vectors */
	_outputs.reserve(_nbLayers + 2);
	_outputs.push_back(Matrix(_nbInputs, 1));
	for (uint_t l(0); l < _nbLayers; ++l)
	{
		_outputs.push_back(Matrix(_layers[l].rowCount(), 1));
	}
	_outputs.push_back(Matrix(_nbOutputs, 1));


	/* Add the output layer's weights */
	_layers.push_back(Matrix(_nbOutputs, _layers[_nbLayers - 1].rowCount()));
	

	/* Randomize the weights */
	for (uint_t l(0); l < _nbLayers + 1; ++l)
	{
		std::cout << "weights[" << l << "]:" << std::endl; /*debug*/

		Matrix& layer(_layers[l]);
		const uint_t rows(layer.rowCount());
		const uint_t cols(layer.colCount());

		for (uint_t i(0); i < rows; ++i)
		{
			for (uint_t j(0); j < cols; ++j)
			{
				layer[i][j] = random_weight();
				std::cout << "  weights[" << i << "," << j << "]: " << layer[i][j] << std::endl; /*debug*/
			}
		}

		std::cout << std::endl; /* debug*/
	}
	std::cout << std::endl; /*debug*/
}

Matrix Network::compute(const Matrix& input)
{
	if (_nbInputs != input.rowCount())
		throw std::invalid_argument("Input vector and argument dimensions do not match");
	
	/* For each layer, the next output is the weight matrix DOT the previous output
	 * to which is applied the activation function.
	 */

	_outputs[0] = input;
	for (uint_t l(0); l < _nbLayers + 1; ++l)
	{
		_outputs[l + 1] = (_layers[l] * _outputs[l]).apply(_activation);
	}

	return _outputs[_nbLayers + 1];
}

float_t Network::random_weight() const
{
	/* TODO: change gaussian parameters
	 * maybe dependent on the network parameters
	 */
	return random_gaussian(1.0, 0.0);
}
