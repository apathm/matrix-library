#include "Matrix.h"

#include<iostream>
#include<stdexcept>
#include<string>
using namespace std;


int main(){
	cout << "Matrix mit 2 rows 2 columns wird initialisiert.\n";
	Matrix m1 {2,2, {1,2,3,4}};

	cout << "Matrix printen\n";
	cout << m1;

	cout << "_____________\n\n";

	vector<double> m{2,1,3,};
	Matrix m2 {1,3, m};

	cout << m2;
	cout << "_______________\n";
	m2.multiply(2);
	cout << m2;
}
