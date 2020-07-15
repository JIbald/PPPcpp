#include "../std_lib_facilities.h"

//(x°C × 9/5) + 32
double ctof (double celsius)
{
    if ( celsius < -273.15 )
    {
        error("ctof() pre-condition");
    }
    
    double fahrenheit {( celsius * 9/5 ) + 32};

    if ( fahrenheit < -459.67 )
    {
        error("ctof() post-condition");
    }

    return fahrenheit;
}

double ftoc (double fahrenheit)
{
    if ( fahrenheit < -459.67 )
    {
        error("ftoc() pre-condition");
    }

    double celsius {( fahrenheit - 32 ) * 5/9};

    if ( celsius < -273.15 )
    {
        error("ftoc() post-condition");
    }
    return celsius;
}

int main()
{
    double celsius {-273.15};
    std::cout << "ctof: " << ctof(celsius) << std::endl;
    double fahrenheit {-459.67};
    std::cout << "ftoc: " << ftoc(fahrenheit) << std::endl;

    return 0;
}