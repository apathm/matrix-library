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
	

	cout << "Nach zuweisung\n";
	m2 = m1;

	cout << m2 << "\n";
}
