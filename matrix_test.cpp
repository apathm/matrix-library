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

	Matrix m3 {1,2};

	

	cout << m3 << "\n";
}
