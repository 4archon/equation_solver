#include <iostream>
#include <fstream>
#include <cmath>
#include "analyser.hpp"
#include "file_rw.hpp"


// file_rw::file_rw(std::string str)
// {
    // this->str = str;
// }

// void file_rw::write(std::string s)
// {
    // std::ofstream out(str, std::ios::app);
    // out << s << "\n";
    // out.close();
// }

void file_rw::write(long double x1, long double x2, Analyser an)
{
    long double x_1, x_2;
    if(!std::isnan(x1) && !std::isnan(x2))
    {
        if (x1 > x2)
        {
            x_1 = x2 - 10;
            x_2 = x1 + 10;
        }
        else
        {
            x_1 = x1 - 10;
            x_2 = x2 + 10;
        }
    }
    else if(!std::isnan(x1))
    {
        x_1 = x1 - 20;
        x_2 = x1 + 20;
    }
    else if(!std::isnan(x2))
    {
        x_1 = x2 - 20;
        x_2 = x2 + 20;
    }
    else
    {
        x_1 = -20;
        x_2 = 20;
    }

    std::ofstream file(".plot.txt");
    file.close();
    std::ofstream out(".plot.txt", std::ios::app);
    out.precision(10);
    long double y;
    x_1 = x_1 + 1;
    while(x_1 < x_2)
    {
        y = x_1 * x_1 * an.a + x_1 * an.b + an.c - an.equal;
        out << std::to_string(x_1) << " " << std::to_string(y) << "\n";
        x_1 = x_1 + 1;
    }
    out.close();
}