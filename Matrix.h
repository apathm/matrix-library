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
	Matrix(int rows = 0, int columns = 0);
	~Matrix();
	double at(int row, int column);
	void print() const;
	size_t size() const;
	void randomize();
	void transpose();
	void multiply(const Matrix& m2);
	void multiply(int scalar);
};

#endif
