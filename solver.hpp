/*
 * solver.hpp
 *
 *  Created on: 28 April 2020
 *      Author: oriel malihi
 */

#ifndef SOLVER_HPP_
#define SOLVER_HPP_

#include <string>
#include <complex>
using namespace std;

namespace solver
{

// ************************ operators ************************************************

class RealVariable
{
public:
    RealVariable *add = NULL;
    double coef_2;
    double coef_1;
    double coef_0;
    RealVariable() : coef_2(0),
                     coef_1(1),
                     coef_0(0) {}

    RealVariable(double c2, double c1, double c0) : coef_2(c2),
                                                    coef_1(c1),
                                                    coef_0(c0) {}
    ~RealVariable()
    {
        //   cout << "delete" << endl;
    }
    friend RealVariable &operator*(double num, RealVariable &x);
    friend RealVariable &operator^(RealVariable &x, double num);
    friend RealVariable &operator/(RealVariable &x, double num);
    friend RealVariable &operator+(RealVariable &x, double num);
    friend RealVariable &operator+(double num, RealVariable &x);
    friend RealVariable &operator-(RealVariable &x, double num);
    friend RealVariable &operator+(RealVariable &x, RealVariable &y);
    friend RealVariable &operator-(RealVariable &x, RealVariable &y);
    friend RealVariable &operator==(RealVariable &x, RealVariable &y);
    friend RealVariable &operator==(RealVariable &x, double num);
    friend RealVariable &operator==(double num, RealVariable &x);
};

// ************************* complex *************************

class ComplexVariable
{
public:
    ComplexVariable *add = NULL;
    double coef_2;
    double coef_1;
    complex<double> comp = 0. + 0i;
    ComplexVariable() : coef_2(0),
                        coef_1(1) {}
    ComplexVariable(double c2, double c1) : coef_2(c2),
                                            coef_1(c1) {}
    ~ComplexVariable()
    {
        //   cout << "delete" << endl;
    }
    friend ComplexVariable &operator*(double num, ComplexVariable &x);
    friend ComplexVariable &operator^(ComplexVariable &x, double num);
    friend ComplexVariable &operator/(ComplexVariable &x, double num);
    friend ComplexVariable &operator+(ComplexVariable &x, double num);
    friend ComplexVariable &operator+(double num, ComplexVariable &x);
    friend ComplexVariable &operator-(ComplexVariable &x, double num);
    friend ComplexVariable &operator-(double num, ComplexVariable &x);
    friend ComplexVariable &operator+(ComplexVariable &x, ComplexVariable &y);
    friend ComplexVariable &operator+(ComplexVariable &x, complex<double> y);
    friend ComplexVariable &operator-(ComplexVariable &x, ComplexVariable &y);
    friend ComplexVariable &operator==(ComplexVariable &x, double num);
    friend ComplexVariable &operator==(double num, ComplexVariable &x);
    friend ComplexVariable &operator==(ComplexVariable &x, ComplexVariable &y);
    friend ComplexVariable &operator==(ComplexVariable &x, complex<double> comp);
    friend ComplexVariable &operator==(complex<double> comp, ComplexVariable &x);
    friend ComplexVariable &operator+(ComplexVariable &x, complex<double> comp);
    friend ComplexVariable &operator+(complex<double> comp, ComplexVariable &x);
    friend ComplexVariable &operator-(complex<double> comp, ComplexVariable &x);
    friend ComplexVariable &operator-(ComplexVariable &x, complex<double> comp);
};

double solve(RealVariable &expr);
complex<double> solve(ComplexVariable &expr);

} // namespace solver

ostream &operator<<(ostream &os, complex<double> comp);

#endif /* SOLVER_HPP_ */
