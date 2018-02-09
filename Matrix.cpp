#include "Matrix.h"
#include<iostream>
#include<vector>
#include<stdexcept>

Matrix::Matrix(int rows, int columns): rows{rows}, columns{columns}{
	if(rows == 0 || columns == 0)
		throw runtime_error("Matrix::Matrix: cannot have 0 as argument.");

	m = new double[rows*columns];

	for(int i{0}; i < rows; ++i)
		for(int j{0}; j < columns; ++j)
			m[i*columns + j] = 0;
}

Matrix::~Matrix(){ delete[] m; };


double& Matrix::at(int row, int column){

	if(row <= 0 || this->rows < row)
		throw runtime_error("Matrix::at: variable row is out of range.");

	if(column <= 0 || this->columns < column)
		throw runtime_error("Matrix::at: variable column is out of range.");

	int index{(row-1)*columns + (column-1)};
	if(index < 0 || index > this->size()-1)
		throw runtime_error("Matrix::at: out of range.");

	return m[(row-1)*columns + (column-1)];
}

const double& Matrix::at(int row, int column) const{
	if(row <= 0 || this->rows < row)
		throw runtime_error("Matrix::at: variable row is out of range.");

	if(column <= 0 || this->columns < column)
		throw runtime_error("Matrix::at: variable column is out of range.");

	int index{(row-1)*columns + (column-1)};
	if(index < 0 || index > this->size()-1)
		throw runtime_error("Matrix::at: out of range.");

	return m[(row-1)*columns + (column-1)];
}

size_t Matrix::size() const{
	return rows*columns;
}



ostream& Matrix::print(ostream& o) const{
	for(int i{1}; i <= rows; ++i){
		o << "|";

		bool first{true};
		for(int j{1}; j <= columns; ++j){
			if(first){
				o << this->at(i, j);
				first = false;
			}
			else
				o << " " << this->at(i, j);
		}

		o << "|\n";
	}

	return o;
}

ostream& operator<<(ostream& o, const Matrix& m){
	return m.print(o);
}
