#ifndef MATRIX_H
#define MATRIX_H

#include<iostream>
#include<vector>
#include<stdexcept>
using namespace std;

class Matrix{
	vector<double> matrix;
	int rows;
	int columns;

	public:
	Matrix(const vector<double>& matrix);
	void transpose();
	void multiply(const Matrix& m2);
	void multiply(int scalar);
};

#endif
