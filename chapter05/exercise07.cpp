#include "../std_lib_facilities.h"

struct quadratic_sol
{
    double plus {0};
    double minus {0};
};

double calc_discriminant (double a, double b, double c)
{
    double disc { b * b - 4 * a * c };

    //post condition
    //discriminant can't be negative
    if (disc < 0)
    {
        error("calc_discriminant() post condition");
    }
    
    return disc; 
}

quadratic_sol quadratic_equ (double a, double b, double c)
{
    quadratic_sol solutions {0, 0};
    solutions.plus = ( -b + sqrt(calc_discriminant(a, b, c) ) ) / ( 2 * a );
    solutions.minus = ( -b - sqrt(calc_discriminant(a, b, c) ) ) / ( 2 * a );
    return solutions;
}

int main()
{
    double a {0}, b {0}, c {0};
    std::cout << "enter a, b, c for a*X*X + b*X + c ( separated by whitespaces ): ";
    std::cin >> a >> b >> c;
    std::cout << std::endl;

    quadratic_sol solutions {quadratic_equ(a, b, c)};
    std::cout << "+ solution: " << solutions.plus << std::endl;
    std::cout << "- solution: " << solutions.minus << std::endl;

    return 0;
}