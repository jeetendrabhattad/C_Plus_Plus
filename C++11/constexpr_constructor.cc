#include <iostream>
/*
 • const: meaning roughly ‘‘I promise not to change this value’’ (§7.5). This is used primarily to specify interfaces, so that data can be passed to functions without fear of it being modified.
The compiler enforces the promise made by const.
• constexpr: meaning roughly ‘‘to be evaluated at compile time’’ (§10.4).
*/
using namespace std;

struct Complex
{
    constexpr Complex(double r, double i) : real(r), imag(i)
    {
    }
    constexpr double getReal() const {return real;}
    constexpr double getImag() const {return imag;}
private:
    double real;
    double imag;
};

int main()
{
    constexpr Complex c1(0.0, 1.0);//literal Complex created at compile time
    double x = 1.1;
    //constexpr Complex c2(x, 1.2); // not allowed as x is not a constant expression
    const Complex c2(x, 1.2);//allowed as this happens at runtime
    const double y = 1.2;
    constexpr Complex c3(y, 1.1);//allowed as y is a constant expression

    Complex c4(1.2, 3.4);//object created at runtime
    return 0;
}
