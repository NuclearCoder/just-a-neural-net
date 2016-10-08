#include "header.h"

Matrix Matrix::operator+(const Matrix& other) const
{
	Matrix result(*this);
	for (uint_t i(0); i < _nbRows; ++i)
	{
		for (uint_t j(0); j < _nbCols; ++j)
		{
			result[i][j] += other[i][j];
		}
	}
	return result;
}

Matrix& Matrix::operator+=(const Matrix& other)
{
	for (uint_t i(0); i < _nbRows; ++i)
	{
		for (uint_t j(0); j < _nbCols; ++j)
		{
			_arr[i][j] += other[i][j];
		}
	}
	return *this;
}

Matrix Matrix::operator-(const Matrix& other) const
{
	Matrix result(*this);
	for (uint_t i(0); i < _nbRows; ++i)
	{
		for (uint_t j(0); j < _nbCols; ++j)
		{
			result[i][j] -= other[i][j];
		}
	}
	return result;
}

Matrix& Matrix::operator-=(const Matrix& other)
{
	for (uint_t i(0); i < _nbRows; ++i)
	{
		for (uint_t j(0); j < _nbCols; ++j)
		{
			_arr[i][j] -= other[i][j];
		}
	}
	return *this;
}

Matrix Matrix::operator*(const float_t scalar) const
{
	Matrix result(*this);
	for (uint_t i(0); i < _nbRows; ++i)
	{
		for (uint_t j(0); j < _nbCols; ++j)
		{
			result[i][j] *= scalar;
		}
	}
	return result;
}

Matrix& Matrix::operator*=(const float_t scalar)
{
	for (uint_t i(0); i < _nbRows; ++i)
	{
		for (uint_t j(0); j < _nbCols; ++j)
		{
			_arr[i][j] *= scalar;
		}
	}
	return *this;
}

Matrix Matrix::operator-() const
{
	Matrix result(_nbRows, _nbCols);
	for (uint_t i(0); i < _nbRows; ++i)
	{
		for (uint_t j(0); j < _nbCols; ++j)
		{
			result[i][j] = -_arr[i][j];
		}
	}
	return result;
}

Matrix Matrix::distance(const Matrix& other) const
{
	Matrix result(*this);
	for (uint_t i(0); i < _nbRows; ++i)
	{
		for (uint_t j(0); j < _nbCols; ++j)
		{
			result[i][j] -= -other[i][j];
			if (result[i][j] < 0) // eek
				result[i][j] = -result[i][j];
		}
	}
	return result;
}