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
	Matrix(int rows = 1, int columns = 1);
	~Matrix();
	double& at(int row, int column);
	const double& at(int row, int column) const;
	ostream& print(ostream& o) const;
	size_t size() const;
	void randomize();
	void transpose();
	void multiply(const Matrix& m2);
	void multiply(int scalar);
};

ostream& operator<<(ostream& o, const Matrix& m);

#endif
