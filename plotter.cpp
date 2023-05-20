#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <unistd.h>
#include "plotter.hpp"


int plotter::plot()
{
    FILE *gp = popen("gnuplot -", "w");
    if (gp == 0)
    {
        return 1;
    }
    fprintf(gp, "set terminal jpeg giant size 1024, 768\n");
    fprintf(gp, "set output 'plot.jpeg'\n");
    fprintf(gp, "plot '.plot.txt' u 1:2 w l title 'equation', (x=0) title 'x=0'\n");
    fclose(gp);
    return 0;
}