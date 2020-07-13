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
    vector <int> vec {}; //contains everything from 2 - input_num
    int input_num {0};
    std::cout << "input your number: ";
    std::cin >> input_num;
    std::cout << std::endl;
    for ( int i = 2; i <= input_num; ++i)
    {
        vec.push_back(i);
    }
    print_intvec(vec);

    vector <int> primes {};
    for ( int i : vec)
    {
        if ( is_prime(i) )
        {
            primes.push_back(i);
        }
    }
    print_intvec(primes);



    return 0;
}