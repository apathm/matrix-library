#include "Matrix.h"
#include<iostream>
#include<vector>
#include<stdexcept>
#include<cassert>
#include<string>

Matrix::Matrix(int rows, int columns, const vector<double>& v): rows{rows}, columns{columns}{
	if(rows == 0 || columns == 0)
		m = nullptr;
	else
		m = new double[rows*columns];

	if(v.size() > 0)
		this->set_values(v); 

	else
		for(size_t i{0}; i < rows; ++i)
			for(size_t j{0}; j < columns; ++j)
				m[i*columns + j] = 0;
}

Matrix::~Matrix(){ delete[] m; }

Matrix::Matrix(const Matrix& original){
	rows = original.rows;
	columns = original.columns;

	m = new double[rows*columns];
	for(size_t i{0}; i < rows; ++i)
		for(size_t j{0}; j < columns; ++j)
			m[i*columns + j] = original.m[i*columns+j];
}

Matrix& Matrix::operator=(const Matrix& original){
	double *mbuf = new double[original.rows * original.columns];
	for(size_t i{0}; i < original.rows; ++i)
		for(size_t j{0}; j < original.columns; ++j)
			mbuf[i*original.columns + j] = original.m[i*original.columns+j];

	if(m) delete[] m;
	m = mbuf;
	rows = original.rows;
	columns = original.columns;
	return *this;
}


double& Matrix::at(int row, int column){
	if(row < 0 || row >= this->rows)
		throw runtime_error("Matrix::at: variable row is out of range.");

	if(column < 0 || this->columns <= column)
		throw runtime_error("Matrix::at: variable column is out of range.");

	int index{row*columns + column};
	if(index < 0 || index > this->size()-1)
		throw runtime_error("Matrix::at: out of range.");

	return m[row*columns + column];
}

const double& Matrix::at(int row, int column) const{
	if(row < 0 || this->rows <= row)
		throw runtime_error("Matrix::at: variable row is out of range.");

	if(column < 0 || this->columns <= column)
		throw runtime_error("Matrix::at: variable column is out of range.");

	int index{row*columns + column};
	if(index < 0 || index > this->size()-1)
		throw runtime_error("Matrix::at: out of range.");

	return m[row*columns + column];
}

size_t Matrix::size() const{
	return rows*columns;
}

Matrix Matrix::set_values(const vector<double>& v){
	if(v.size() > this->size())
		throw runtime_error("Matrix::set_values: too many values provided.");

	vector<double> temp {v};
	if(v.size() < this->size())
		for(size_t i{v.size()}; i < this->size(); ++i)
			temp.push_back(0);
		
	assert(temp.size() == this->size());

	for(size_t i{0}; i < rows; ++i)
		for(size_t j{0}; j < columns; ++j)
			this->at(i,j) = temp.at(i*columns + j);	

	return *this;
}


Matrix& Matrix::multiply(int scalar){
	for(size_t i{0}; i < rows; ++i)
		for(size_t j{0}; j < columns; ++j)
			this->at(i,j) *= scalar;

	return *this;
}

Matrix& Matrix::multiply(const Matrix& m){
	if(this->columns != m.rows)
		throw runtime_error("Matrix::multiply: number of columns of this->matrix does not match number of rows of Matrix m.");

	vector<double> temp;

	for(size_t i{0}; i < this->rows; ++i){
		for(size_t j{0}; j < m.columns; ++j){
			double sum{0};

			for(size_t k{0}; k < m.rows; ++k)
				sum += this->at(i, k) * m.at(k, j);

			temp.push_back(sum);
		}
	}

	Matrix temp_m {this->rows, m.columns, temp};

	*this = temp_m;
	return *this;
}

Matrix& Matrix::add(const Matrix& m){
	if(this->rows != m.rows || this->columns != m.columns)
		throw runtime_error("Matrix::add: Matrices do not have same dimensions");

	for(size_t i{0}; i < rows; ++i)
		for(size_t j{0}; j < columns; ++j)
			this->at(i, j) += m.at(i,j);

	return *this;
}

Matrix& Matrix::substract(const Matrix& m){
	if(this->rows != m.rows || this->columns != m.columns)
		throw runtime_error("Matrix::add: Matrices do not have same dimensions");

	for(size_t i{0}; i < rows; ++i)
		for(size_t j{0}; j < columns; ++j)
			this->at(i, j) -= m.at(i,j);

	return *this;
}

Matrix& Matrix::operator+(const Matrix& m){
	return this->add(m);
}
Matrix& Matrix::operator-(const Matrix& m){
	return this->substract(m);
}
Matrix& Matrix::operator*(int scalar){
	return this->multiply(scalar);
}
Matrix& Matrix::operator*(const Matrix& m){
	return this->multiply(m);
}

Matrix& Matrix::transpose(){
	vector<double> temp;

	for(size_t i{0}; i < columns; ++i)
		for(size_t j{0}; j < rows; ++j)
			temp.push_back(this->at(j, i));
	
	Matrix m {this->columns, this->rows, temp};
	*this = m;

	return *this;
}


ostream& Matrix::print(ostream& o) const{
	for(size_t i{0}; i < rows; ++i){
		o << "|";

		bool first{true};
		for(size_t j{0}; j < columns; ++j){
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
