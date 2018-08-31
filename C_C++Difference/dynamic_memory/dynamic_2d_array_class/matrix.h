#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
    int **matrix;
    int iRows;
    int iCols;
    public:
    //manager methods : methods which manage creation and destruction of objects
    Matrix(const int rows, const int cols);//allocate 
    Matrix(const Matrix& existingMatrix);//copy constructor
    //1. Matrix m1(10,10); Matrix m2(m1);
    //2. Add(m1, m2) --> Matrix Add(Matrix x1, Matrix x2); -- when it is pass by value 
    //3. return m --> Matrix Add(...)--> returning by value
    ~Matrix();//de-allocate
    
    //mutator methods - which change the state
    void Accept();
    //Accessor methods - which return the state
    void Display();
    //General Methods - all other methods
    Matrix Add(const Matrix &m2) const;
    Matrix Sub(const Matrix &m2) const;
    Matrix Multiply(const Matrix &m2) const;
    //m1 + m2 ----> m1.operator+(m2)---- m1.add(m2)
    //m1 = m2 ----> m1.operator=(m2)
    //Matrix * const this = &callingObject;
    Matrix& operator=(const Matrix& m2);
    //const Matrix * const this = &callingObject;
    Matrix operator+(const Matrix& m2) const;
/*<return-type> operator<actual-operator> ([<argument>]);*/
    Matrix operator-(const Matrix& m2) const;
    //+=
    Matrix operator+=(const Matrix& m2);
};
#endif
