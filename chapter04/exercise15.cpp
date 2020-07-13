#include "../std_lib_facilities.h"

//same as exercise13.cpp hte amount of prime numbers is always less than n.

vector <int> prime_eratosthenes (int num)
{
    vector <int> vec;
    for (int i = 2; i <= num; i++)
    {
        vec.push_back(i);
    }

    //int counter1 {0};
    for ( int i = 0; i <= std::sqrt(num); ++i )
    {
        //++counter1;
        //std::cout << "==========OUTER: " << counter1 << " ==========" << " i: " << i << " ==========" << std::endl;

        //int counter2 {0};
        for ( int j = i + 1; j < vec.size(); ++j )
        {
            //++counter2;
            //std::cout << "==========INNER: " << counter2 << " ==========" << " j: " << j << " ==========" << std::endl;
            if ( vec[j] % vec[i] == 0 )
            {
                vec.erase(vec.begin() + j);
            }
        }
    }
    return vec;
}

void display_vector (vector <int> vec)
{
    for ( int i : vec )
    {
        std::cout << "| " << i << " ";
    }
    std::cout << std::endl << std::endl;
}

int main()
{
    int num {0};
    std::cout << "enter an integer n to display the first n primes from 0 up to n: ";
    std::cin >> num;
    std::cout << std::endl;

    vector <int> vec {prime_eratosthenes(num)};
    display_vector(vec);
    

    return 0;
}