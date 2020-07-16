#include "std_lib_facilities.h"

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

vector <double> vec_entry_diff (vector <double> vec)
{
    vector <double> diffs {};
    for( int i {0}; i < vec.size(); ++i )
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
    vector <double> vec {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 5};
    display_vector(vec);
    display_vector(vec_entry_diff(vec));
    
    return 0;
}