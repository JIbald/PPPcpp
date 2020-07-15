#include "../std_lib_facilities.h"

double ctok (double c)
{
    double k = c + 273.15;
    return k;
}

int main()
{
    double c = 0;
    std::cin >> c;
    double k = ctok(c);
    std::cout << k << std::endl;

    return 0;
}