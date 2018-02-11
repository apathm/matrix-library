#include "Matrix.h"

#include<iostream>
#include<stdexcept>
#include<string>
using namespace std;


int main(){
	Matrix m1{2,2,{1,2,3,4}};

	Matrix m2{2, 3, {1,2,3,4,5,6}};


	m2.transpose();
	cout << m2 << "\n";
	cout << m1.transpose() << "\n";
}
