#include "../std_lib_facilities.h"
//ficticious values
constexpr double yen_per_dollar {2}; 
constexpr double kroner_per_dollar {3};
constexpr double pounds_per_dollar {4};

constexpr double yen_per_kroner {yen_per_dollar / kroner_per_dollar}; //  (2/3)
constexpr double pounds_per_kroner {pounds_per_dollar / kroner_per_dollar};//   (4/3)
constexpr double dollar_per_kroner {1 / kroner_per_dollar};//    (1/3)

constexpr double kroner_per_yen {1 / yen_per_kroner}; //    (3/2))
constexpr double pounds_per_yen { pounds_per_dollar / yen_per_dollar}; //    2
constexpr double dollar_per_yen {1 / yen_per_dollar}; //    (1/2)


double from_dollar (double amount, char currency)
{
    switch(currency)
    {
        case 'y':
        {
            amount *= yen_per_dollar;
            return amount;
        }
        case 'k':
        {
            amount *= kroner_per_dollar;
            return amount;
        }
        case 'p':
        {
            amount *= pounds_per_dollar;
            return amount;
        }
        default:
        {
            return -0.1;
        }
    }
}

double from_kroner (double amount, char currency)
{
    switch(currency)
    {
        case 'y':
        {
            amount *= yen_per_kroner;
            return amount;
        }
        case 'p':
        {
            amount *= pounds_per_kroner;
            return amount;
        }
        case 'd':
        {
            amount *= dollar_per_kroner;
            return amount;
        }
        default:
        {
            return -0.1;
        }
    }
}

double from_yen (double amount, char currency)
{
    switch(currency)
    {
        case 'k':
        {
            amount *= kroner_per_yen;
            return amount;
        }
        case 'p':
        {
            amount *= pounds_per_yen;
            return amount;
        }
        case 'd':
        {
            amount *= dollar_per_yen;
            return amount;
        }
        default:
        {
            return -0.1;
        }
    }
}

int main()
{
    char unit_from {' '};
    char unit_to {' '};
    double amount {0};
    double result {0};

    std::cout << "enter initial currency (d/k/y): ";
    std::cin >> unit_from;
    std::cout << std::endl;

    std::cout << "enter target currency (k/y/p): ";
    std::cin >> unit_to;
    std::cout << std::endl;

    std::cout << "enter your amount: ";
    std::cin >> amount;
    std::cout << std::endl;

    switch(unit_from)
    {
        case 'd':
        {
            result = from_dollar(amount, unit_to);
            break;
        }
        case 'k':
        {
            result = from_kroner(amount, unit_to);
            break;
        }
        case 'y':
        {
            result = from_yen(amount, unit_to);
            break;
        }
        default:
        {
            std::cout << "Sumimasen, but this system doesn't know your currency.";
            break;
        }
    }
    std::cout << amount << " " << unit_from << " are " << result << " " << unit_to << std::endl;
    return 0;
}


