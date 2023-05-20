#include <iostream>
#include <cmath>
#include "quadeq.hpp"


// abs
void QuadraticEq::set_coef(long double a, long double b, long double c)
{
    this->a = a;
    this->b = b;
    this->c = c;
}


QuadraticEq::QuadraticEq(long double a, long double b, long double c)
{
    set_coef(a, b, c);
}

std::string QuadraticEq::eq_string()
{
    return "this is abstract";
}


// 1
Eq_1type::Eq_1type(long double a, long double b, long double c): QuadraticEq(a,b,c)
{
    x1 = NAN;
    x2 = NAN;
}

std::string Eq_1type::eq_string()
{
    return "Решение - вся область действительных чисел";
}

// 2
void Eq_2type::calc()
{
    x1 = NAN;
    x2 = NAN;
}

Eq_2type::Eq_2type(long double a, long double b, long double c): QuadraticEq(a, b, c)
{
    calc();
}

std::string Eq_2type::eq_string()
{
    return "Не имеет решений";
}

// 3

void Eq_3type::calc()
{
    long double D = b*b - 4*a*c;
    if (D < 0)
    {
        x1 = NAN;
        x2 = NAN;
    }
    else if (D == 0)
    {
        x1 = (-b + std::sqrt(D))/(2*a);
        x2 = NAN;
    }
    else 
    {
        x1 = (-b + std::sqrt(D))/(2*a);
        x2 = (-b - std::sqrt(D))/(2*a);
    }
}


Eq_3type::Eq_3type(long double a, long double b, long double c): QuadraticEq(a, b, c)
{
    calc();
}

std::string Eq_3type::eq_string()
{
    return "x1: " + std::to_string(x1) + " x2: " + std::to_string(x2);
}

// 4

void Eq_4type::calc()
{
    x1 = 0;
    x2 = -b / a;    
}


Eq_4type::Eq_4type(long double a, long double b, long double c): QuadraticEq(a, b, c)
{
    calc();
}

std::string Eq_4type::eq_string()
{
    return "x1: " + std::to_string(x1) + " x2: " + std::to_string(x2);
}

// 5

void Eq_5type::calc()
{
    if ((-c / a) < 0)
    {
        x1 = NAN;
        x2 = NAN;
    }
    else
    {
        x1 = (std::sqrt(-c / a));
        x2 = -(std::sqrt(-c / a));
    }
}


Eq_5type::Eq_5type(long double a, long double b, long double c): QuadraticEq(a, b, c)
{
    calc();
}

std::string Eq_5type::eq_string()
{
    if (std::isnan(x1)) return "Корней на действительной прямой нет";
    else return "x1: " + std::to_string(x1) + " x2: " + std::to_string(x2);
}

// 6

void Eq_6type::calc()
{
    x1 = 0;
    x2 = NAN;
}

Eq_6type::Eq_6type(long double a, long double b, long double c): QuadraticEq(a, b, c)
{
    calc();
}

std::string Eq_6type::eq_string()
{
    return "Единственный корень: " + std::to_string(x1);
}


// 7

void Eq_7type::calc()
{
    x1 = -c / b;
    x2 = NAN;
}

Eq_7type::Eq_7type(long double a, long double b, long double c): QuadraticEq(a, b, c)
{
    calc();
}

std::string Eq_7type::eq_string()
{
    return "Единственный корень: " + std::to_string(x1);
}

// 8

void Eq_8type::calc()
{
    x1 = 0;
    x2 = NAN;
}

Eq_8type::Eq_8type(long double a, long double b, long double c): QuadraticEq(a, b, c)
{
    calc();
}

std::string Eq_8type::eq_string()
{
    return "Единственный корень: " + std::to_string(x1);
}
