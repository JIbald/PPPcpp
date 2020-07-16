#include "../std_lib_facilities.h"

void display_vector (vector <int> vec)
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
    std::cout << std::endl;
}

int sum_n_vec_entries (vector <int> vec, int n)
{
    //pre condition
    //vector can't be empty, n can't be larger than vec.size() or smaller than zero
    if( vec.empty() || (n > vec.size() ) || n < 0 )
    {
        error("sum_n_vec_entries() pre condition");
    } 

    int sum {0};
    vector <int> negatives {};
    for( int i{0}; i < n; ++i )
    {   
        if( i < 0 )
        {
            negatives.push_back(i);
        }
        sum += vec[i];
    }

    //warn the user if his numbers (accidentally) contain a negative
    if( !negatives.empty() )
    {
        std::cout << "WARNING: your entries contain negatives:\n";
        for(int i : negatives)
        {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    return sum;
}

int main()
{
    int n {0};
    std::cout << "Enter the number of values you want to sum: ";
    std::cin >> n;
    std::cout << std::endl;

    vector <int> vec {};
    int input {0};
    std::cout << "Enter some integers (press \"|\" to stop):\n";
    while( std::cin >> input )
    {
        vec.push_back(input);
    }

    int sum {sum_n_vec_entries(vec, n)};
    display_vector(vec);
    std::cout << "the sum of the first " << n << " integers is: " << sum << std::endl;
    


    return 0;
}