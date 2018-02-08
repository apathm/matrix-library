#include "Matrix.h"
#include<iostream>
#include<vector>
#include<stdexcept>

Matrix::Matrix(int rows, int columns): rows{rows}, columns{columns}{
	m = new double[rows*columns];

	for(int i{0}; i < rows; ++i)
		for(int j{0}; j < columns; ++j)
			m[i * j] = 0;
}


double Matrix::at(int row, int column){
	if(row <= 0 || this->rows < row)
		throw runtime_error("Matrix::at: variable row is out of range.");

	if(column <= 0 || this->columns < column)
		throw runtime_error("Matrix:.at: variable column is out of range.");

	return m[(row-1)*columns - (column-1)];
}
