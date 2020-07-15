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

int main()
{
    double c = 0;
    std::cin >> c;
    
    double k = ctok(c);
    std::cout << k << std::endl;

    return 0;
}