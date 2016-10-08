#include "header.h"

Network::Network(const uint_t nbInputs, const uint_t nbOutputs,
					const std::vector<uint_t> layers,
					const floatfun_t actFun, const floatfun_t actFunDiff)
	: _nbInputs(nbInputs), _nbOutputs(nbOutputs), _nbLayers(layers.size()),
		_actFun(actFun), _actFunDiff(actFunDiff)
{
	/* Create weight matrices and output/error vectors based on the layerSize vector */
	_weights.reserve(_nbLayers + 1);
	_errors.reserve(_nbLayers + 1);
	_outputs.reserve(_nbLayers + 2);
	_activations.reserve(_nbLayers + 1);

	_outputs.push_back(Matrix(nbInputs, 1));

	uint_t prevSize(nbInputs);
	for (uint_t layerSize : layers)
	{
		_weights.push_back(Matrix(layerSize, prevSize));
		_errors.push_back(Matrix(layerSize, 1));
		_outputs.push_back(Matrix(layerSize, 1));
		_activations.push_back(Matrix(layerSize, 1));
		prevSize = layerSize;
	}

	_weights.push_back(Matrix(_nbOutputs, prevSize));
	_weights.push_back(Matrix(_nbOutputs, 1));
	_outputs.push_back(Matrix(_nbOutputs, 1));
	_activations.push_back(Matrix(_nbOutputs, 1));


	/* Randomize the weights */
	for (uint_t l(0); l < _nbLayers + 1; ++l)
	{
		debug() << "weights[" << l << "]:" << std::endl;

		Matrix& layer(_weights[l]);
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

float_t Network::random_weight() const
{
	/* TODO: change gaussian parameters
	* maybe dependent on the network parameters
	*/
	return random_gaussian(0.0F, 1.0F);
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
		_activations[l] = _weights[l] * _outputs[l];
		_outputs[l + 1] = _activations[l].apply(_actFun);
	}

	return _outputs[_nbLayers + 1];
}

void Network::train(const Matrix& input, const Matrix& expected)
{
	const uint_t n(_nbLayers); // faster to type, less messy to look at


	/* First, compute the network's output. */
	const Matrix& output(compute(input));


	/* Propagate the error backwards */


	// TODO: vectorize this
	const Matrix& distance(expected.distance(output));
	for (uint_t i(0); i < _nbOutputs; ++i) // initalize the output error
	{
		_errors[_nbLayers][i][0] = _actFunDiff(_activations[_nbLayers - 1][i][0])
									* distance[i][0];
	}

	for (uint_t k(n); k >= 1; ++k) // for each layer backwards
	{
		for (uint_t j(0); j < _outputs[k - 1].colCount(); ++j)
		{
			float_t sum(0);
			for (uint_t i(0); i < _outputs[k].colCount(); ++i)
			{
				sum += _weights[k][i][j] * _errors[k][i][0];
			}
			_errors[k - 1][j][0] = _actFunDiff(_activations[k - 1][j][0])
									* sum;
		}
	}
	
	/*  */

}