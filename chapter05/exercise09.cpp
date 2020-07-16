//I see no point in this exercise. 
//It might just be written wrong and should be switched with exercise 10.
// however, to do this exercise, I would go as follows:

#include "../std_lib_facilities.h"

//changed vector entry type
void display_vector (vector <double> vec)
{
    //pre-condition
    //vector can't be empty
    if(vec.empty() )
    {
        error("display_vector() pre-condition");
    }
    for( double i : vec ) //int i -> double i
    {
        std::cout << "| " << i << " ";
    }
    std::cout << "|" << std::endl;
}

//return type int stays vector needs to be double
int sum_n_vec_entries (vector <double> vec, int n)
{
    //pre condition
    //vector can't be empty, n can't be larger than vec.size() or smaller than zero
    if( vec.empty() || (n > vec.size() ) || n < 0 )
    {
        error("sum_n_vec_entries() pre condition");
    } 

    double double_sum {0};
    int sum {0};
    vector <double> negatives {};
    for( int i{0}; i < n; ++i )
    {   
        if( i < 0 )
        {
            negatives.push_back(i);
        }
        double_sum += vec[i];
    }
    sum = double_sum; //this was first within the for loop, which could be right still, though this would cause problems with adding 0.x fractions

    //warn the user if his numbers (accidentally) contain a negative
    if( !negatives.empty() )
    {
        std::cout << "WARNING: your entries contain negatives:\n";
        for(double i : negatives)
        {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    //post condition added:
    if( sum != double_sum )
    {
        error("sum_n_vec_entries() post condition: integer sum is inprecise.");
    }
    return sum;
}

int main()
{
    int n {0};
    std::cout << "Enter the number of values you want to sum: ";
    std::cin >> n;
    std::cout << std::endl;

    vector <double> vec {}; //this vector needs to contain doubles so it can get handed to sum_n_vec_entries()
    double input {0}; //musn't forget this guy needs to be a double
    std::cout << "Enter some integers (press \"|\" to stop):\n";
    while( std::cin >> input )
    {
        vec.push_back(input);
    }

    int sum {sum_n_vec_entries(vec, n)};
    display_vector(vec);
    std::cout << "the sum of the first " << n << " integers is: " << sum << std::endl;
    
    vec.erase(vec.begin(), vec.end());

    return 0;
}