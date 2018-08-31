#include "dynamic2darray.h"
#include <iostream>
#include <assert.h>
int*** Create3d(const int planes, const int rows, const int cols)
{
	int ***matrix = NULL;

    matrix = new int**[planes];
	assert(matrix!=NULL);
    for(int i = 0 ; i < planes ; i++)
    {
	    matrix[i] = new int*[rows];
	    assert(matrix[i]!=NULL);
	    for(int j = 0 ; j < rows ; j++)
	    {
		    matrix[i][j] = new int[cols];
		    assert(matrix[i][j]!=NULL);
	    }
    }
	return matrix;
}

int** Create(const int rows, const int cols)
{
	int **matrix = NULL;

	matrix = new int*[rows];
	assert(matrix!=NULL);
	for(int i = 0 ; i < rows ; i++)
	{
		matrix[i] = new int[cols];
		assert(matrix[i]!=NULL);
	}
	return matrix;
}

void Accept(int **const matrix, const int rows, const int cols)
{
	assert(matrix!=NULL);
	assert(rows>0);
	assert(cols>0);

	for( int i = 0 ; i < rows ; i++)
	{
		for(int j = 0 ; j < cols ; j++)
		{
            std::cin>>matrix[i][j];
		}
	}
}

void Display(const int **const matrix, const int rows, const int cols)
{
	assert(matrix!=NULL);
	assert(rows>0);
	assert(cols>0);
	for( int i = 0 ; i < rows ; i++)
	{
		for(int j = 0 ; j < cols ; j++)
		{
            std::cout<<matrix[i][j]<<"\t";
		}
	    std::cout<<"\n";
    }
}

void FreeDynamicArray(int **matrix, const int rows)
{
	assert(matrix!=NULL);
	assert(rows>0);
	
	for(int i = 0 ; i < rows ; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

void FreeDynamic3dArray(int ***matrix, const int rows, const int cols)
{
	assert(matrix!=NULL);
	assert(rows>0);
	assert(cols>0);
	for(int i = 0 ; i < rows ; i++)
    {
	    for(int j = 0 ; j < cols ; j++)
	    {
		    delete[] matrix[i][j];
	    }
    	delete[] matrix[i];
    }
    delete[] matrix;
}
int** AddMatrix(const int **const matrix1, const int **const matrix2, const int rows, const int cols)
{
	assert(matrix1!=NULL);
	assert(matrix2!=NULL);
	assert(rows>0);
	assert(cols>0);
	
	int **resultmatrix = Create(rows, cols);
	
	for (int i = 0 ; i < rows ; i++)
	{
		for(int j = 0 ; j < cols ; j++)
		{
			resultmatrix[i][j] = matrix1[i][j]+matrix2[i][j];
		}
	}

	return resultmatrix;
}
