

class QuadraticEq
{
public:
    long double a, b, c;
    long double x1, x2;
public:
    QuadraticEq() = default;

    QuadraticEq(long double, long double, long double);

    void set_coef(long double, long double, long double);

    virtual std::string eq_string();
};


//1 0 = 0
class Eq_1type: public QuadraticEq
{
public:
    Eq_1type(long double, long double, long double);

    std::string eq_string() override;
};


//2 c = 0
class Eq_2type: public QuadraticEq
{
public:
    Eq_2type(long double, long double, long double);

    void calc();

    std::string eq_string()  override;
};


//3 ax^2+bx+c = 0
class Eq_3type: public QuadraticEq
{
public:
    Eq_3type(long double, long double, long double);

    void calc();

    std::string eq_string() override;
};


//4 ax^2+bx = 0
class Eq_4type: public QuadraticEq
{
public:
    Eq_4type(long double, long double, long double);

    void calc();

    std::string eq_string() override;
};


//5 ax^2+c = 0
class Eq_5type: public QuadraticEq
{
public:
    Eq_5type(long double, long double, long double);

    void calc();

    std::string eq_string() override;
};


//6 ax^2 = 0
class Eq_6type: public QuadraticEq
{
public:
    Eq_6type(long double, long double, long double);

    void calc();

    std::string eq_string() override;
};


//7 bx+c = 0
class Eq_7type: public QuadraticEq
{
public:
    Eq_7type(long double, long double, long double);

    void calc();

    std::string eq_string() override;
};


//8 bx = 0
class Eq_8type: public QuadraticEq
{
public:
    Eq_8type(long double, long double, long double);

    void calc();

    std::string eq_string() override;
};