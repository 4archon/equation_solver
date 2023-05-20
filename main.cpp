#include <iostream>
#include <fstream>
#include <cmath>
#include <unistd.h>
#include "quadeq.hpp"
#include "analyser.hpp"
#include "solver.hpp"
#include "file_rw.hpp"
#include "plotter.hpp"


int main(int argc, char *argv[])
{
    // std::string str = "123.321x^2+456.654x-200.20=2020.2023";
    // std::string str = "-x^2-x-20=20";
    // std::string str = "x^2+2x-3=0";
    
    
    std::string str;
    Analyser anl;
    std::cout << "Введите уравнение\n";
    std::cout << "Введите exit для выхода\n";
    while(true)
    {
        std::cin >> str;
        if(str == "exit") return 0;
        anl.set_string(str);
        try
        {
            anl.analyse();
        }
        catch (std::invalid_argument error)
        {
            std::cout << "Некоректный ввод. Попробуйте снова\n";
            continue;
        }
        Solver s(anl);
        std::cout << s.show_solution() << "\n";
        std::cout << "Хотите построить график?[y|n]\n";
        std::string str2;
        std::cin >> str2;
        if(str2 == "exit") return 0;
        if(str2[0] == 'y')
        {
            file_rw r;
            r.write(s.eq->x1, s.eq->x2, anl);
            plotter p;
            int error = p.plot();
            system("rm .plot.txt");
            if(error == 1)
            {
                std::cout << "Произошла ошибка при создании графика\n";
            }
            else if(error == 0)
            {
                system("open plot.jpeg");
                std::cout << "Хотите сохранить график?[y|n]\n";
                std::string str3;
                std::cin >> str3;
                if(str3[0] != 'y')
                {
                    system("rm plot.jpeg");
                }
            }
        }
        std::cout << "Хотите решить новое уравнение?[y|n]\n";
        std::string str4;
        std::cin >> str4;
        if(str4[0] == 'y') continue;
        else break;
    }

    
    
    

    // std::string str;

    // if (argc > 1) str = argv[1];
    // else str = "";


    // if (str == "")
    // {
        // std::cout << "da";
    // }
    // else if (str == "-h")
    // {
        // std::cout << "      Решение квадратных уравнений" << "\n";
        // std::cout << "      Можно запускать без параментров" << "\n";
        // std::cout << "      Первый аргумент либо -f, либо уравнение" << "\n";
        // std::cout << "      Если указан флаг -f второй аргумент имя файла" << "\n";
        // std::cout << "      -h показать это описание" << "\n";
    // }
    // else if (str == "-f")
    // {
        // std::cout << "file";
    // }



}