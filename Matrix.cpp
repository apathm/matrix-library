#include "Matrix.h"
#include<iostream>
#include<vector>
#include<stdexcept>
#include<cassert>
#include<string>

Matrix::Matrix(int rows, int columns, const vector<double>& v): rows{rows}, columns{columns}{
	if(rows == 0 || columns == 0)
		throw runtime_error("Matrix::Matrix: cannot have 0 as argument.");

	m = new double[rows*columns];

	if(v.size() > 0)
		this->set_values(v); 

	else
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

void Matrix::set_values(const vector<double>& v){
	if(v.size() > this->size())
		throw runtime_error("Matrix::set_values: too many values provided.");

	vector<double> temp {v};
	if(v.size() < this->size())
		for(size_t i{v.size()}; i < this->size(); ++i)
			temp.push_back(0);
		
	assert(temp.size() == this->size());

	for(size_t i{1}; i <= rows; ++i)
		for(size_t j{1}; j <= columns; ++j)
			this->at(i,j) = temp.at((i-1)*columns + (j-1));	
}


void Matrix::multiply(int scalar){
	for(size_t i{1}; i <= rows; ++i)
		for(size_t j{1}; j <= columns; ++j)
			this->at(i,j) *= scalar;
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
