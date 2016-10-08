#include "header.h"

Matrix::Matrix(const uint_t nbRows, const uint_t nbCols)
	: _nbRows(nbRows), _nbCols(nbCols), _arr(nbRows)
{
	for (uint_t i(0); i < nbRows; ++i)
	{
		_arr[i] = std::vector<float_t>(nbCols);
	}
}

Matrix::Matrix(const Matrix& copy)
	: _nbRows(copy._nbRows), _nbCols(copy._nbCols), _arr(_nbRows)
{
	for (uint_t i(0); i < _nbRows; ++i)
	{
		_arr[i].resize(_nbCols);
		for (uint_t j(0); j < _nbCols; ++j)
		{
			_arr[i][j] = copy[i][j];
		}
	}
}

Matrix Matrix::identity(const uint_t size)
{
	Matrix result(size, size);
	for (uint_t i(0); i < size; ++i)
	{
		result[i][i] = static_cast<float_t>(1.0);
	}
	return result;
}

Matrix Matrix::apply(floatfun_t func) const
{
	Matrix result(_nbRows, _nbCols);
	for (uint_t i(0); i < _nbRows; ++i)
	{
		for (uint_t j(0); j <_nbCols; ++j)
		{
			result[i][j] = func(_arr[i][j]);
		}
	}
	return result;
}