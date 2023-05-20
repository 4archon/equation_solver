

class Solver
{
public:
    QuadraticEq * eq;
public:

    Solver(long double, long double, long double);

    Solver(Analyser);

    void setter(long double, long double, long double);

    ~Solver();

    std::string show_solution();
};
