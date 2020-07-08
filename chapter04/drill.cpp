#include "../std_lib_facilities.h"

//tried to make it so that no whitespace used would still be valid (something like : 12cm)
//but couldn't make it work.

int main()
{
    double a {0};
    double max {0};
    double min {0};
    double sum {0};
    int counter {0};
    vector <double> num_collection {};

    string unit {};
    vector <std::string> unit_storage {};

    std::cout << "enter a number with a unit: ";
    while (std::cin >> a >> unit)
    {
        sum += a;
        ++counter;
        num_collection.push_back(a);
        
        if (unit == "cm" || unit == "m" || unit == "in" || unit == "ft")
        {
            //conversion
            if (unit == "cm")
            {
                a *= 0.01;
            }
            else if (unit == "in")
            {
                a *= (2.54 * 0.01);
            }
            else if (unit == "ft")
            {
                a *= (12 * 2.54 * 0.01);
            }

            std::cout << "you entered: " << a << unit << std::endl;

            //set min max accordingly
            if(a < max)
            {
                min = a;
                std::cout << "smaller value: " << min << " larger value: " << max;
            }
            else if (a > max)
            {
                min = max;
                max = a;
                std::cout << "smaller value: " << min << " larger value: " << max;
            }
            else
            {
                min = a;
                std::cout << min << " and " << max << " are of equal size.";
            }
            
            std::cout << std::endl;

            //check if difference is "almost equal"
            if ( (max - min) <= (1.0 / 100) )
            {
                std::cout << "the numbers are almost equal." << std::endl;
            }
        }
        else
        {
            std::cout << "system does not accept this unit." << std::endl;
        }
    }
    std::cout << "sum of all entered numbers: " << sum << std::endl;
    std::cout << "amount of numbers entered: " << counter << std::endl;

    std::sort(num_collection.begin(), num_collection.end() );
    std::cout << "| ";
    for(double i : num_collection)
    {
        std::cout << i << " |";
    }
    std::cout << std::endl;
    std::cout << unit << std::endl;
    
 
    return 0;
}