#include "header.h"

Network::Network(const uint_t nbInputs, const uint_t nbOutputs,
					const std::vector<uint_t> layers, const floatfun_t actFun)
	: _nbInputs(nbInputs), _nbOutputs(nbOutputs), _nbLayers(layers.size()),
		_actFun(actFun)
{
	/* Create weight matrices and output vectors based on the layerSize vector */
	_layers.reserve(_nbLayers + 1);
	_outputs.reserve(_nbLayers + 2);
	_activations.reserve(_nbLayers + 1);

	_outputs.push_back(Matrix(nbInputs, 1));

	uint_t prevSize(nbInputs);
	for (uint_t layerSize : layers)
	{
		_layers.push_back(Matrix(layerSize, prevSize));
		_outputs.push_back(Matrix(layerSize, 1));
		_activations.push_back(Matrix(layerSize, 1));
		prevSize = layerSize;
	}

	_layers.push_back(Matrix(_nbOutputs, prevSize));
	_outputs.push_back(Matrix(_nbOutputs, 1));
	_activations.push_back(Matrix(_nbOutputs, 1));


	/* Randomize the weights */
	for (uint_t l(0); l < _nbLayers + 1; ++l)
	{
		debug() << "weights[" << l << "]:" << std::endl;

		Matrix& layer(_layers[l]);
		const uint_t rows(layer.rowCount());
		const uint_t cols(layer.colCount());

		for (uint_t i(0); i < rows; ++i)
		{
			for (uint_t j(0); j < cols; ++j)
			{
				layer[i][j] = random_weight();
				debug() << "  weights[" << i << "," << j << "]: " << layer[i][j] << std::endl;
			}
		}

		debug() << std::endl; /* debug*/
	}
	debug() << std::endl; /*debug*/
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
		_activations[l] = _layers[l] * _outputs[l];
		_outputs[l + 1] = _activations[l].apply(_actFun);
	}

	return _outputs[_nbLayers + 1];
}

float_t Network::random_weight() const
{
	/* TODO: change gaussian parameters
	 * maybe dependent on the network parameters
	 */
	return random_gaussian(0.0F, 1.0F);
}
