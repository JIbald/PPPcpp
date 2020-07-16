//I guess I accidentally did this already. Almost. Should be just changing the return value from sum_n_vec_entries.
//and creating the n-1 diff vector of course.
//let's get going.

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
    for( double i : vec )
    {
        std::cout << "| " << i << " ";
    }
    std::cout << "|" << std::endl;
}

double sum_n_vec_entries (vector <double> vec, int n)
{
    //pre condition
    //vector can't be empty, n can't be larger than vec.size() or smaller than zero
    if( vec.empty() || (n > vec.size() ) || n < 0 )
    {
        error("sum_n_vec_entries() pre condition");
    } 

    double double_sum {0};
    vector <double> negatives {};
    for( int i{0}; i < n; ++i )
    {   
        if( i < 0 )
        {
            negatives.push_back(i);
        }
        double_sum += vec[i];
    }

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

    return double_sum;
}

vector <double> vec_entry_diff (vector <double> vec, int n)
{
    //pre condition
    //vector can't be empty, n can't be larger than vec.size() or smaller than zero
    if( vec.empty() || (n > vec.size() ) || n < 0 )
    {
        error("sum_n_vec_entries() pre condition");
    } 

    vector <double> diffs {};
    for( int i {0}; i < n; ++i )
    {
        if(i+1 < vec.size() )
        {
            double max {vec[i]};
            double min {vec[i+1]};
            double temp {0};
            double diff {0};

            if( max < min )
            {
                temp = max;
                max = min;
                min = temp;
            }
            /*
            else if( max == min )
            {
                diffs.push_back(0);
            }
            */
            diffs.push_back(max - min);
        }
    }
    return diffs;
}

int main()
{
    int n {0};
    std::cout << "Enter the number of values (n) you want to sum: ";
    std::cin >> n;
    std::cout << std::endl;

    vector <double> vec {}; //this vector needs to contain doubles so it can get handed to sum_n_vec_entries()
    double input {0}; //musn't forget this guy needs to be a double
    std::cout << "Enter some integers (press \"|\" to stop):\n";
    while( std::cin >> input )
    {
        vec.push_back(input);
    }

    double sum {sum_n_vec_entries(vec, n)};
    display_vector(vec);
    std::cout << "the sum of the first " << n << " integers is: " << sum << std::endl;
    
    std::cout << "the following values are the differences between (n-1) adjacent values:\n";
    display_vector(vec_entry_diff(vec, n));

    vec.erase(vec.begin(), vec.end());

    return 0;
}