

class Analyser
{
public:
    std::string str;
    long double a = 0;
    long double b = 0;
    long double c = 0;
    long double equal = 0;
public:
    Analyser() = default;

    void set_string(std::string);

    void analyse();
};


