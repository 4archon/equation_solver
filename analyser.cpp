#include <iostream>
#include "analyser.hpp"


void Analyser::set_string(std::string str)
{
    this->str = str;
}

void Analyser::analyse()
{
    std::string str_copy = str;
    if(std::string::npos == str.find("=")) throw std::invalid_argument("Не уравнение");
    for(int i = 0; i < str_copy.length(); i++)
    {
        if(str_copy[i] == '=')
        {
            std::string c_str = str_copy.substr(0, i);
            // std::cout << "c:" << c_str <<"\n";
            if(c_str != "") c = std::stold(c_str);
            else c = 0;
            std::string equal_str = str_copy.substr(i+1, str_copy.length() - i - 1);
            // std::cout << "e:" << equal_str <<"\n";
            if(equal_str != "") equal = std::stold(equal_str);
            else equal = 0;
            break;
        }
        else if(str_copy[i] == 'x' && str_copy[i+1] == '^')
        {
            std::string a_str = str_copy.substr(0, i);
            // std::cout << "a:" << a_str <<"\n";
            if (a_str == "-") a = -1;
            else if(a_str != "") a = std::stold(a_str);
            else a = 1;
            str_copy = str_copy.substr(i+3, str_copy.length() - i - 3);
            i = -1;
        }
        else if(str_copy[i] == 'x')
        {
            std::string b_str = str_copy.substr(0, i);
            // std::cout << "b:" << b_str <<"\n";
            if (b_str == "-") b = -1;
            else if(b_str == "+") b = 1;
            else if(b_str != "") b = std::stold(b_str);
            else b = 1;
            str_copy = str_copy.substr(i+1, str_copy.length() - i - 1);
            i = -1;
        }
    }
}
