#include "../std_lib_facilities.h"
#include <vector>

int main()
{
    int pennies {0};
    int nickels {0};
    int dimes {0};
    int quarters {0};
    int half_dollars {0};
    int one_dollars {0};

    std::cout << "enter number of coins in following order (seperated by whitespace):\n"
        << "pennies, nickels, dimes, quarters, half_dollars, one_dollars:\n";

    std::cin >> pennies >> nickels >> dimes >> quarters >> half_dollars >> one_dollars;

    int sum_cents {pennies + nickels*5 + dimes*10 + quarters*25 + half_dollars*50 + one_dollars*100};
    double sum_dollar {static_cast <double> (sum_cents) / 100};

    std::cout << "you have: " << sum_dollar << " $ in coins." << std::endl;


    return 0;
}