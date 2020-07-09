#include "../std_lib_facilities.h"

int main()
{
    //read doubles into vector
    vector <double> vec {};
    double value {0};
    while(std::cin >> value)
    {
        vec.push_back(value);
        
    }
    for( double i : vec )
    {
        std::cout << "| " << i << " ";
    }
    std::cout << std::endl;

    //calculate the sum of all vector entries
    double sum {0};
    for (double i : vec )
    {
        sum += i;
    }
    std::cout << "sum of all entries: " << sum << std::endl;
    
    //calculate min and max
    double min {vec[0]};
    double max {vec[0]};
    for ( double i : vec )
    {
        if ( i < min)
        {
            min = i;
        }
        else if (i > max)
        {
            max = i;
        }
    }
    std::cout << "max: " << max << " min: " << min << std::endl;

    //calculate the means
    double means = sum / vec.size();
    std::cout << "means of all entries: " << means << std::endl;
    

    return 0;
}