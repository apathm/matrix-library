#include "Matrix.h"

#include<iostream>
#include<stdexcept>
#include<string>
using namespace std;


int main(){
	Matrix m1{2,2,{1,2,3,4}};

	Matrix m2{4,4};

	cout << m1 << "\n";
	cout << m2 << "\n";
	

	m2 = m1.multiply(2);

	cout << m2 << "\n";
}
