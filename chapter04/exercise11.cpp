#include "../std_lib_facilities.h"

void print_intvec ( vector <int> vec )
{
    for ( int i : vec )
    {
        std::cout << " " << i << "|";
    }
    std::cout << std::endl << std::endl;
}

bool is_prime ( int num )
{
    for ( int i = 2; i < 10; ++i )
    {
        if ( i != num && (num % i == 0) )
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    return false;
}

int main()
{
    vector <int> hundred {}; //contains everything from 2 - 100
    for ( int i = 2; i <= 100; ++i)
    {
        hundred.push_back(i);
    }
    print_intvec(hundred);

    vector <int> primes {};
    for ( int i : hundred)
    {
        if ( is_prime(i) )
        {
            hundred.push_back(i);
        }
    }
    print_intvec(primes);



    return 0;
}