#include "matrix.h"
#include <iostream>

/*Initialization List Purposes :
 i) Performing true initialization
 ii) Initializing const & reference members
 iii) Invoking base class constructor
 The order of execution of initalization list happens in the order of declaration of members inside class irrespective of order in which it is written
 */

Matrix::Matrix(const int rows, const int cols) 
    : iRows(rows), iCols(cols), matrix(0) //initialization list
{
    /* Assignment
    iRows = rows;
    iCols = cols;
    */
    std::cout<<"Matrix::Matrix\n";
    matrix = new int*[rows];
    for(int i = 0 ; i < rows ; i++)
        matrix[i] = new int[cols];
}//allocate 
/*
    Default Compiler Provided Methods :
    i) Default constructor (no arguments constructor i.e which can be invoked without any arguments). Compiler provides this iff user has nor provided any constructor.
    ii) Default Copy Constructor : Copy constructor is a method which gets invoked implicitly on creation of new object from existing object.
    Possible scenarios :
        - Matrix m3(m1) : explicitly creating new object from existing
        - Add(m1) : passing object as an argument to a function using pass by value method
        - return m1 : returning object from method using pass by value

    Compiler Provided Copy Constructor Performs Shallow copy.
    When to write user-defined Copy Constructor ?
    - when object refers to some resources which are dynamically allocated or referring to some other memory areas.
    iii) Compiler provides default assignment operator.
 */
Matrix::Matrix(const Matrix& existingMatrix)
    : iRows(existingMatrix.iRows), iCols(existingMatrix.iCols)
{
    //this : constant reference to calling object
    std::cout<<"Matrix Copy Constructor\n";
    this->matrix = new int*[iRows];
    for(int i = 0 ; i < iRows ; i++)
        this->matrix[i] = new int[iCols];

    for(int i = 0 ; i < iRows ; i++)
        for(int j = 0 ; j < iCols ; j++)
            this->matrix[i][j] = existingMatrix.matrix[i][j];
}//copy constructor
Matrix::~Matrix()
{
    std::cout<<"Matrix::~Matrix\n";
    if(matrix)
    {
        for(int i = 0 ; i < iRows  ; i++)
            delete[] matrix[i];

        delete[] matrix;
    }
}//de-allocate
    
//Please implement all the below methods
void Matrix::Accept()
{
    std::cout<<"Matrix::Accept\n";
}
void Matrix::Display()
{
    std::cout<<"Matrix::Display\n";
}
Matrix Matrix::Add(const Matrix &m2) const
{
    std::cout<<"Matrix::Add\n";
    return Matrix(m2.iRows, m2.iCols);
}
Matrix Matrix::Sub(const Matrix &m2) const
{
    std::cout<<"Matrix::Sub\n";
    return Matrix(m2.iRows, m2.iCols);
}
Matrix Matrix::Multiply(const Matrix &m2) const
{
    std::cout<<"Matrix::Multiply\n";
    return Matrix(m2.iRows, m2.iCols);
}
Matrix& Matrix::operator=(const Matrix& m2)
{
    std::cout<<"Matrix::operator=\n";
    if(this->iRows != m2.iRows || this->iCols != m2.iCols)
    {
        //TBD
        //free this->matrix and allocate again with m2.iRows and m2.iCols. 
    }
    this->iRows = m2.iRows;
    this->iCols = m2.iCols;
    for(int i = 0 ; i < m2.iRows ; i++)
        for(int j = 0 ; j < m2.iCols ; j++)
            this->matrix[i][j] = m2.matrix[i][j];

    return *this;
}
Matrix Matrix::operator+(const Matrix& m2) const
{
    std::cout<<"Matrix::operator+\n";
    return Add(m2);
}
Matrix Matrix::operator-(const Matrix& m2) const
{
    std::cout<<"Matrix::operator-\n";
    return Sub(m2);
}
Matrix Matrix::operator+=(const Matrix& m2)
{
    std::cout<<"Matrix::operator+=\n";
    Matrix m3 = Add(m2);
    
    for(int i = 0 ; i < m3.iRows ; i++)
        for(int j = 0 ; j < m3.iCols ; j++)
            this->matrix[i][j] = m3.matrix[i][j];
    
    return *this;
}
//provide operator overloaded multiply method
int main()
{
    Matrix m1(3, 3);
    m1.Accept();
    Matrix m2(m1);
    
    m1.Display();
    m2.Display();

    Matrix m3 = m1.Add(m2);
    m3.Display();
    //assignment
    std::cout<<"Assignment Operator\n";
    m3 = m2;
    //+
    std::cout<<"+ Operator & Copy Constructor(expected but optimized by compiler where m4 is passed as a reference to add and new object creation directly happens for m4 hence no copy constructor invocation is seen\n";
    Matrix m4(m1 + m2);
    // - & assignment
    std::cout<<"- Operator & Assignment Operator\n";
    m4 = m1 - m2;
   //+=
    std::cout<<"+= Operator\n";
    m4 += m1;
    return 0;
}
