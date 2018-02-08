#ifndef MATRIX_H
#define MATRIX_H

#include<iostream>
#include<vector>
#include<stdexcept>
using namespace std;

class Matrix{
	int rows;
	int columns;
	double *m;

	public:
	Matrix(int rows, int columns);
	~Matrix();
	void randomize();
	void transpose();
	void multiply(const Matrix& m2);
	void multiply(int scalar);
};

#endif
