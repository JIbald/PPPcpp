#include "../std_lib_facilities.h"

int main()
{
    double a {0};
    double b {0};
    double c {0};
    std::cout << "Enter your quadratic equation in the style of:\n";
    std::cout << "a*a*X + b*X + c (seperated by whitespace)\n";
    std::cin >> a >> b >> c;

    const double discriminant { b*b - 4*a*c };
    if ( discriminant < 0)
    {
        std::cout << "negative discriminant, this system does not handle imaginary numbers." << std::endl;
    }
    else if ( discriminant == 0 )
    {
        const double sol_zero { ( -b ) / ( 2*a ) };
        std::cout << "discriminant is zero.\n";
        std::cout << "soution: " << sol_zero;
    }
    else
    {
        const double sol_plus { ( -b + std::sqrt( discriminant ) ) / ( 2*a ) };
        const double sol_minus { ( -b - std::sqrt( discriminant ) ) / ( 2*a ) };
        std::cout << "discriminant: " << discriminant << std::endl;
        std::cout << "solution plus: " << sol_plus << std::endl;
        std::cout << "solution minus: " << sol_minus << std::endl;
    }
    
    return 0;
}