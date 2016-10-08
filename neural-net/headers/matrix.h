#pragma once

#include <vector>

/* All the operators assume dimensions are correct,
 * except the normal product operator
 */

class Matrix
{
public:
	static Matrix identity(const uint_t size);

	Matrix(const uint_t nbRows, const uint_t nbCols);
	Matrix(const Matrix& copy);

	/* Naive transpose algorithm, heh whatever */
	Matrix transpose() const;

	/* Product term by term */
	Matrix hadamard(const Matrix& other) const;
	
	/* The unsigned difference of the two matrices */
	Matrix distance(const Matrix& other) const;

	Matrix& operator=(const Matrix copy);

	Matrix operator+(const Matrix& other) const;
	Matrix operator-(const Matrix& other) const;

	Matrix& operator+=(const Matrix& other);
	Matrix& operator-=(const Matrix& other);

	Matrix operator*(const float_t scalar) const;
	Matrix& operator*=(const float_t scalar);

	Matrix operator-() const;

	Matrix operator*(const Matrix& other) const;

	Matrix apply(floatfun_t func) const;

	inline uint_t rowCount() const { return _nbRows; }
	
	inline uint_t colCount() const { return _nbCols; }

	inline std::vector<float_t>& operator[](const int i) { return _arr[i]; }
	
	inline const std::vector<float_t>& operator[](const int i) const { return _arr[i]; }

private:
	Matrix multiply_naive(const Matrix& other) const;

	const unsigned int _nbRows;
	const unsigned int _nbCols;

	std::vector<std::vector<float_t>> _arr;

};

std::ostream& operator<<(std::ostream& out, const Matrix& mat);