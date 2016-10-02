#include "header.h"

Matrix& Matrix::operator=(const Matrix copy)
{
	if (_nbRows != copy._nbRows)
		throw std::invalid_argument("Argument row count does not match");
	if (_nbCols != copy._nbCols)
		throw std::invalid_argument("Argument column count does not match");
	for (uint_t i(0); i < _nbRows; ++i)
	{
		for (uint_t j(0); j < _nbCols; ++j)
		{
			_arr[i][j] = copy[i][j];
		}
	}
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Matrix& mat)
{
	/* this will be ugly af */

	const uint_t rows(mat.rowCount());
	const uint_t cols(mat.colCount());

	out << '[' << std::endl;
	for (uint_t i(0); i < rows; ++i)
	{
		out << "  ";
		for (uint_t j(0); j < cols; ++j)
		{
			out << mat[i][j] << ", ";
		}
		out << std::endl;
	}
	out << ']';
	return out;
}