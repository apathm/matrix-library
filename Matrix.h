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
	Matrix(int rows = 0, int columns = 0, const vector<double>& v = {});
	~Matrix();
	Matrix(const Matrix& original);
	Matrix& operator=(const Matrix& original);
	double& at(int row, int column);
	const double& at(int row, int column) const;
	Matrix set_values(const vector<double>& v);
	ostream& print(ostream& o) const;
	size_t size() const;
	Matrix& transpose();
	Matrix& multiply(const Matrix& m);
	Matrix& multiply(int scalar);
	Matrix& add(const Matrix& m);
	Matrix& substract(const Matrix& m);
	Matrix& operator+(const Matrix& m);
	Matrix& operator-(const Matrix& m);
	Matrix& operator*(int scalar);
	Matrix& operator*(const Matrix& m);
};

ostream& operator<<(ostream& o, const Matrix& m);

#endif
