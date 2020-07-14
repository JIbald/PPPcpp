#include "../std_lib_facilities.h"

int main()
{
    vector <double> temp {76.5, 73.5, 71.0, 73.6, 70.1, 72.5, 77.6, 85.3, 88.5, 91.7, 95.9, 99.2, 98.2, 100.6, 106.3, 112.4, 110.2, 103.6, 94.9, 91.7, 88.4, 85.2, 85.4, 87.7};

    double sum {0};
    double max_temp {temp[0]};
    double min_temp {temp[0]};
    
    for ( double i : temp )
    {
        if( i > max_temp )
        {
            max_temp = i;
        }
        if ( i < min_temp )
        {
            min_temp = i;
        }
        sum += i;
    }
    std::cout << "max_temp: " << max_temp << std::endl;
    std::cout << "min_temp: " << min_temp << std::endl;
    std::cout << "average_temp: " << sum / temp.size() << std::endl;

    return 0;
}