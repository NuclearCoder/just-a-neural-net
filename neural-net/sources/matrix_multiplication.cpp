#include "header.h"

Matrix Matrix::operator*(const Matrix& other) const
{
	if (!check_mult_dim(other))
	{
		throw std::invalid_argument("Dimensions did not match");
	} 
	return multiply_naive(other);
	/*  we won't have enormous matrices so stick with the naive algorithm for now (probably less than size 25x25) */
}

bool Matrix::check_mult_dim(const Matrix& other) const
{
	return _nbCols == other._nbRows;
}

Matrix Matrix::multiply_naive(const Matrix& other) const
{
	Matrix result(_nbRows, other._nbCols);
	for (uint_t i(0); i < _nbRows; ++i)
	{
		for (uint_t j(0); j < other._nbCols; ++j)
		{
			result[i][j] = static_cast<float_t>(0.0F);
			for (uint_t k(0); k < _nbCols; ++k) /*  c_(i,j) = sum( a_(i,k) * b_(k,j) )  */
			{
				result[i][j] += _arr[i][k] * other[k][j];
			}
		}
	}
	return result;
}


// TODO: strassen algorithm