#include "std_lib_facilities.h"

int factorial (int num);

int main()
{
    int test {5};

    std::cout << factorial(test) << std::endl;
    
    return 0;
}

int factorial (int num)
{
    int sum {1};
    for ( int i = num; i >= 1; --i )
    {
        sum *= i;
    }
    return sum;
}