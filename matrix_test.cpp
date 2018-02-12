#include "Matrix.h"

#include<iostream>
#include<stdexcept>
#include<string>
using namespace std;


int main(){
	Matrix m1 {2, 3, {4,2,1,0,-2,4}};
	Matrix m2 {3,3, {1,2,3,0,4,6,2,-1,8}};

	cout << m1 << "\n";
	cout << m2 << "\n";

	cout << "Multiply matrices\n";
	cout << m1.multiply(m2) << "\n";

	cout << "Transpose matrix\n";
	cout << m1.transpose() << "\n";

	cout << "Multiply by scalar\n";
	cout << m1.multiply(2) << "\n";  
}
