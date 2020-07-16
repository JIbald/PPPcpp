#include "../std_lib_facilities.h"

double ctof (double celsius)
{
    //pre condition
    //checks for argument below absolute zero
    if ( celsius < -273.15 )
    {
        error("ctof() pre-condition");
    }
    
    double fahrenheit {( celsius * 9/5 ) + 32};

    //post condition
    //checks for return parameter below absolute zero
    if ( fahrenheit < -459.67 )
    {
        error("ctof() post-condition");
    }

    return fahrenheit;
}

double ftoc (double fahrenheit)
{
    //pre condition
    //checks for argument below absolute zero
    if ( fahrenheit < -459.67 )
    {
        error("ftoc() pre-condition");
    }

    double celsius {( fahrenheit - 32 ) * 5/9};

    //post condition
    //checks for return parameter below absolute zero
    if ( celsius < -273.15 )
    {
        error("ftoc() post-condition");
    }
    return celsius;
}

int main()
{
    double temperature {0};
    char unit {' '};
    
    std::cout << "enter temperature, whitespace, unit (Celsius: c / Fahrenheit: f): ";
    std::cin >> temperature >> unit;

    double conv_temp {0};
    switch(unit)
    {
        case 'c':
            conv_temp = ctof(temperature);
            break;

        case 'f':
            conv_temp = ftoc(temperature);
            break;
        
        default:
            std::cout << "unknown unit." << std::endl;
    }

    std::cout << "converted temperature: " << conv_temp << " " << unit << std::endl;

    return 0;
}