/*
 * solver.cpp
 *
 *  Created on: 28 April 2020
 *      Author: oriel malihi
 */
#include <string>
#include <iostream>
#include <cmath>
#include "solver.hpp"
using namespace std;

namespace solver
{

//*************** friend real **************************

RealVariable &operator*(double num, RealVariable &x)
{
    if (x.add == NULL)
    {
        RealVariable *temp = new RealVariable(0, num, 0);
        temp->add = temp;
        return *temp;
    }
    else
    {
        x.coef_2 *= num;
        x.coef_1 *= num;
        x.coef_0 *= num;
        return x;
    }
}

RealVariable &operator^(RealVariable &x, double num)
{
    if (x.add == NULL)
    {
        RealVariable *temp = new RealVariable(1, 0, 0);
        temp->add = temp;
        return *temp;
    }
    else
    {
        x.coef_2 = x.coef_1 * x.coef_1;
        x.coef_1 = 0;
        x.coef_0 *= x.coef_0;
        return x;
    }
}
RealVariable &operator/(RealVariable &x, double num)
{
    if (x.add == NULL)
    {
        double t = 1 / num;
        RealVariable *temp = new RealVariable(0, t, 0);
        temp->add = temp;
        return *temp;
    }
    else
    {
        x.coef_2 /= num;
        x.coef_1 /= num;
        x.coef_0 /= num;
        return x;
    }
}
RealVariable &operator+(RealVariable &x, double num)
{
    if (x.add == NULL)
    {
        RealVariable *temp = new RealVariable(0, 1, num);
        temp->add = temp;
        return *temp;
    }
    else
    {
        x.coef_0 += num;
        return x;
    }
}
RealVariable &operator+(double num, RealVariable &x)
{
    return x + num;
}

RealVariable &operator-(RealVariable &x, double num)
{
    return x + (-1) * num;
}
RealVariable &operator+(RealVariable &x, RealVariable &y)
{
    if (x.add == NULL)
    {
        RealVariable *temp = new RealVariable(y.coef_2, y.coef_1 + 1, y.coef_0);
        temp->add = temp;
        delete y.add;
        return *temp;
    }
    else
    {
        x.coef_2 += y.coef_2;
        x.coef_1 += y.coef_1;
        x.coef_0 += y.coef_0;
        delete y.add;
        return x;
    }
}
RealVariable &operator-(RealVariable &x, RealVariable &y)
{
    return x + ((-1) * y);
}

RealVariable &operator==(RealVariable &x, RealVariable &y)
{
    return x - y;
}
RealVariable &operator==(RealVariable &x, double num)
{
    return x - num;
}
RealVariable &operator==(double num, RealVariable &x)
{
    return x - num;
}

double solve(RealVariable &x)
{
    double ans = -1;
    if (x.coef_2 != 0)
    {
        double a = x.coef_2;
        double b = x.coef_1;
        double c = x.coef_0;
        double t = b * b - 4.0 * a * c;
        if (t < 0)
        {
            delete x.add;
            throw runtime_error("There is no real solution");
        }
        ans = sqrt(t) - b;
        ans /= a * 2;
        delete x.add;
    }
    else if (x.coef_1 != 0)
    {
        ans = (x.coef_0 / x.coef_1) * (-1);
        delete x.add;
    }
    else
    {
        delete x.add;
        throw runtime_error("ERR: cant do this math. wrong input");
    }
    return ans;
}

//************** friend comp **********************************************

ComplexVariable &operator*(double num, ComplexVariable &x)
{
    if (x.add == NULL)
    {
        ComplexVariable *temp = new ComplexVariable(0, num);
        temp->add = temp;
        return *temp;
    }
    else
    {
        x.coef_2 *= num;
        x.coef_1 *= num;
        x.comp *= num;
        return x;
    }
}

ComplexVariable &operator^(ComplexVariable &x, double num)
{
    if (x.add == NULL)
    {
        ComplexVariable *temp = new ComplexVariable(1, 0);
        temp->add = temp;
        return *temp;
    }
    else
    {
        x.coef_2 = x.coef_1 * x.coef_1;
        x.coef_1 = 0;
        x.comp *= x.comp;
        return x;
    }
}
ComplexVariable &operator/(ComplexVariable &x, double num)
{
    if (x.add == NULL)
    {
        double t = 1 / num;
        ComplexVariable *temp = new ComplexVariable(0, t);
        temp->add = temp;
        return *temp;
    }
    else
    {
        x.coef_2 /= num;
        x.coef_1 /= num;
        x.comp /= num;
        return x;
    }
}
ComplexVariable &operator+(ComplexVariable &x, double num)
{
    if (x.add == NULL)
    {
        ComplexVariable *temp = new ComplexVariable(0, 1);
        temp->comp = num + 0i;
        temp->add = temp;
        return *temp;
    }
    else
    {
        x.comp += num;
        return x;
    }
}
ComplexVariable &operator+(ComplexVariable &x, complex<double> y)
{
    if (x.add == NULL)
    {
        ComplexVariable *temp = new ComplexVariable(0, 1);
        temp->comp = y;
        temp->add = temp;
        return *temp;
    }
    else
    {
        x.comp += y;
        return x;
    }
}
ComplexVariable &operator+(double num, ComplexVariable &x)
{
    return x + num;
}

ComplexVariable &operator-(ComplexVariable &x, double num)
{
    return x + (-1) * num;
}
ComplexVariable &operator+(ComplexVariable &x, ComplexVariable &y)
{
    if (x.add == NULL)
    {
        ComplexVariable *temp = new ComplexVariable(y.coef_2, y.coef_1 + 1);
        temp->comp = y.comp;
        temp->add = temp;
        delete y.add;
        return *temp;
    }
    else
    {
        x.coef_2 += y.coef_2;
        x.coef_1 += y.coef_1;
        x.comp += y.comp;
        delete y.add;
        return x;
    }
}
ComplexVariable &operator-(ComplexVariable &x, ComplexVariable &y)
{
    return x + ((-1) * y);
}
ComplexVariable &operator+(complex<double> comp, ComplexVariable &x)
{
    return x + comp;
}
ComplexVariable &operator-(complex<double> comp, ComplexVariable &x)
{
    return x - comp;
}
ComplexVariable &operator-(ComplexVariable &x, complex<double> comp)
{
    return x + (-1.0)*comp;
}
ComplexVariable &operator-(double num, ComplexVariable &x){
    return x - num;
}
ComplexVariable &operator==(double num, ComplexVariable &x)
{
    return x - num;
}

ComplexVariable &operator==(ComplexVariable &x, ComplexVariable &y)
{
    return x - y;
}
ComplexVariable &operator==(ComplexVariable &x, double num)
{
    return x - num;
}
ComplexVariable &operator==(ComplexVariable &x, complex<double> comp)
{
    return x - comp;
}
ComplexVariable &operator==(complex<double> comp, ComplexVariable &x)
{
    return x - comp;
}

complex<double> solve(ComplexVariable &x)
{
    complex<double> ans = 0. + 0i;
    if (x.coef_2 != 0)
    {
        double a = x.coef_2;
        double b = x.coef_1;
        complex<double> c = x.comp;
        ans = (b * b - 4.0 * a * c);
        if(c.imag() != 0){
            delete x.add;
            throw runtime_error("Math error! cant perform sqrt to imaginary variable");
        }
        ans = sqrt(ans) - b;
        ans /= a * 2;
        delete x.add;
    }
    else if (x.coef_1 != 0)
    {
        ans = (x.comp / x.coef_1) * (-1.0);
        delete x.add;
    }
    else
    {
        delete x.add;
        throw runtime_error("ERR: cant do this math. wrong input");
    }
    if (ans.imag() == 0)
    {
        ans.imag(0);
    }
    if (ans.real() == 0)
    {
        ans.real(0);
    }
    return ans;
}

} // namespace solver

ostream &operator<<(ostream &os, complex<double> comp)
{
    if (comp.imag() >= 0)
    {
        return (os << comp.real() << "+" << comp.imag() << "i");
    }
    else
    {
        return (os << comp.real() << comp.imag() << "i");
    }
}
