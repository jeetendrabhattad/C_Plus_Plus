#include "dynamic2darray.h"
#include <iostream>

void SimulateDynamicMatrixOperations()
{
	int **matrix1, **matrix2, **resultmatrix;
	int rows1, cols1, rows2, cols2;
	
    std::cout<<"Enter dimensions for matrix1:-";
    std::cin>>rows1>>cols1;
    std::cout<<"Creating Matrix1 !!!\n";
	matrix1 = Create(rows1, cols1);

    std::cout<<"\nEnter dimensions for matrix2:-";
    std::cin>>rows2>>cols2;
    std::cout<<"\nCreating Matrix2 !!!";
	matrix2 = Create(rows2, cols2);

    std::cout<<"\nEnter values for Matrix1 !!!";
	Accept(matrix1, rows1, cols1);
    std::cout<<"\nEnter values for Matrix2 !!!";
	Accept(matrix2, rows2, cols2);

    std::cout<<"\nMatrix 1 is \n";
	Display((const int ** const)matrix1, rows1, cols1);
    std::cout<<"\nMatrix 2 is \n";
	Display((const int ** const)matrix2, rows2, cols2);
	
    std::cout<<"\nAdding 2 matrices !!!\n";
	resultmatrix = AddMatrix((const int ** const)matrix1, (const int ** const)matrix2, rows1, cols1);
    std::cout<<"\nResult of Addition is ....\n";
	Display((const int ** const)resultmatrix, rows1, cols1);

    std::cout<<"\nFreeing Matrix 1 !!!";
	FreeDynamicArray(matrix1, rows1);	
    std::cout<<"\nFreeing Matrix 2 !!!";
	FreeDynamicArray(matrix2, rows2);	
    std::cout<<"\nFreeing ResultMatrix !!!";
	FreeDynamicArray(resultmatrix, rows2);	
}

int main()
{
	SimulateDynamicMatrixOperations();
	return 0;
}
