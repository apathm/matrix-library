# Matrix - Library

A toy matrix library to learn more about some C++ concepts. 

### Usage

There are three ways to initialize a matrix.

```
// Create an empty matrix 
Matrix m;

// Specify rows and columns (all values will be set to 0)
Matrix m {2,2};

// Pass vector to set the values
// Note: if vector is less than matrix size
// all following values will be set to 0
Matrix m {2,2, {1,2,3,4}};

```

This class provides operator<< overloading so to print a matrix simply use

```
cout << m;
```

It also provides all the basic matrix operations

* Add two matrices together - 'm + m2'
* Substract two matrices - 'm - m2'
* Multiply a matrix with a scalar - 'm * scalar'
* Multiply two matrices - 'm * m2'
* Transpose a matrix - m.tranpose();