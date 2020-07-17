#include "../std_lib_facilities.h"

void display_int_vector (vector <unsigned int> vec)
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

vector <unsigned int> n_fibonaccies (int n)
{
    vector <unsigned int> fibo {1, 1};
    unsigned int fibo_num {0};
    for( unsigned int i = 1; i <= n -2; ++i )
    {
        fibo_num = fibo[i] + fibo[i-1];
        //I guess this is cheating.
        //I gave this func something large and looked up the last number that was unsigned
        //and was essentially too lazy too count on what position it sat in the vector. Sue me ;)
        if( fibo_num == 1836311903)
        {
            std::cout << "It is the " << i <<"th iteration." << std::endl;
        }
        fibo.push_back(fibo_num);
    }

    return fibo;
}

int main()
{
    int n {0};

    std::cout << "enter how many fibonacci numbers you want: ";
    std::cin >> n;

    vector <unsigned int> n_vec {};
    for( unsigned int i {1}; i <= n; ++i)
    {
        n_vec.push_back(i);
    }
    display_int_vector(n_vec);

    vector <unsigned int> fibovec {n_fibonaccies(n)};
    display_int_vector(fibovec);

    std:cout << std::endl;

    return 0;
}