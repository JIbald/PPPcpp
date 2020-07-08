#include "../std_lib_facilities.h"

int main()
{
    //ficticious values
    constexpr double yen_per_dollar {2}; 
    constexpr double kroner_per_dollar {3};
    constexpr double pounds_per_dollar {4};
    
    char unit {' '};
    double amount {0};

    std::cout << "please enter your amount[$] and the currency you wish to receive(y/k/p): ";
    std::cin >> amount >> unit;
    std::cout << std::endl;
    
    switch(unit)
    {
        case 'y':
        {
            amount *= yen_per_dollar;
            std::cout << "amount: " << amount << " Yen\n";
            break;
        }
        case 'k':
        {
            amount *= kroner_per_dollar;
            std::cout << "amount: " << amount << " Kroner\n";
            break;
        }
        case 'p':
        {
            amount *= pounds_per_dollar;
            std::cout << "amount: " << amount << " Pounds\n";
            break;
        }
        default:
        {
            std::cout << "this currency is either not in the system or you used capital letters." << std::endl;
        }
    }



    return 0;
}