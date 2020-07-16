#include "../std_lib_facilities.h"

void display_int_vector (vector <int> vec)
{
    //pre-condition
    //vector can't be empty
    if(vec.empty() )
    {
        error("display_vector() pre-condition");
    }
    for( int i : vec )
    {
        std::cout << "| " << i << " ";
    }
    std::cout << "|" << std::endl;
}

vector <int> n_fibonaccies (int n)
{
    vector <int> fibo {1, 1};
    for( int i = 1; i <= n -2; ++i )
    {
        fibo.push_back( fibo[i] + fibo[i-1] );
    }

    return fibo;
}

int main()
{
    int n {0};

    std::cout << "enter how many fibonacci numbers you want: ";
    std::cin >> n;

    vector <int> n_vec {};
    for( int i {1}; i <= n; ++i)
    {
        n_vec.push_back(i);
    }
    display_int_vector(n_vec);

    vector <int> fibovec {n_fibonaccies(n)};
    display_int_vector(fibovec);

    std:cout << std::endl;



    return 0;
}