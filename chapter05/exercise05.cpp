#include "../std_lib_facilities.h"

double ctok (double c)
{
    if ( c < -273.15 )
    {
        error("ctok() pre-condition");
    }
    double k = c + 273.15;
    if ( k < 0 )
    {
        error("ctok() post-condition");
    }
    return k;
}

double ktoc (double k)
{
    if ( k < 0 )
    {
        error("ktoc() pre-condition");
    }
    double c = k - 273.15;
    if ( c < -273.15 )
    {
        error("ktoc() post-condition");
    }
    return c;
}

int main()
{
    double temp {0};
    char unit {' '};
    std::cout << "enter temperature as either Celsius (c) or Kelvin (k), separated by a whitespace: ";
    std::cin >> temp >> unit;

    double conv_temp {0};
    switch (unit)
    {
        case 'c':
            conv_temp = ctok(temp);
            break;

        case 'k':
            conv_temp = ktoc(temp);
            break;

        default:
            error("main() unknown unit input.");
            break;
    }
    std::cout << "converted temperature: " << conv_temp << " " << unit << std::endl;

    return 0;
}