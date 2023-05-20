#include <iostream>
#include "quadeq.hpp"
#include "analyser.hpp"
#include "solver.hpp"



Solver::Solver(long double a, long double b, long double c)
{
    setter(a,b,c);
}

void Solver::setter(long double a, long double b, long double c)
{
    if(a == 0 && b == 0 && c ==0) eq = new Eq_1type(a, b, c);
    else if(a == 0 && b == 0 && c !=0) eq = new Eq_2type(a, b, c);
    else if(a != 0 && b != 0 && c !=0) eq = new Eq_3type(a, b, c);
    else if(a != 0 && b != 0 && c ==0) eq = new Eq_4type(a, b, c);
    else if(a != 0 && b == 0 && c !=0) eq = new Eq_5type(a, b, c);
    else if(a != 0 && b == 0 && c ==0) eq = new Eq_6type(a, b, c);
    else if(a == 0 && b != 0 && c !=0) eq = new Eq_7type(a, b, c);
    else if(a == 0 && b != 0 && c ==0) eq = new Eq_8type(a, b, c);
}

Solver::~Solver()
{
    delete eq;
}

std::string Solver::show_solution()
{
    return eq->eq_string();
}

Solver::Solver(Analyser an)
{
    setter(an.a, an.b, an.c - an.equal);
}
