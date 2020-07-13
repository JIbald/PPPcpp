#include "../std_lib_facilities.h"

void print_intvec ( vector <int> vec )
{
    for ( int i : vec )
    {
        std::cout << " " << i << "|";
    }
    std::cout << std::endl << std::endl;
}

//unsure if this function can be faulty
bool is_prime ( int num )
{
    for ( int i = 2; i < num; ++i )
    {
        if ( i != num && (num % i == 0) )
        {
            std::cout << num << "is not prime" << std::endl;
            return false;
        }
        
    }
    std::cout << num << "is prime" << std::endl;
    return true;
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
            primes.push_back(i);
        }
    }
    print_intvec(primes);



    return 0;
}