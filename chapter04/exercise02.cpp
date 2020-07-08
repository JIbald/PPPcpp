#include "../std_lib_facilities.h"

int main()
{
    vector <double> temps;

    for (double temp; std::cin >> temp;)
    {
        temps.push_back(temp);
    }

    //compute mean temperature
    double sum {0};
    for (double x : temps )
    {
        sum += x;
    }
    double avg_temp {sum / temps.size()};
    std::cout << "average temperature: " << avg_temp << std::endl;

    //compute median temperature
    sort(temps.begin(), temps.end());
    double median_temp {0};
    if( temps.size() % 2 != 0 )
    {
        median_temp = temps[temps.size() / 2];
        std::cout << "the median temp is: " << median_temp << std::endl;
    }
    else
    {
        std::cout << "no true median" << std::endl;
    }
    


        

    return 0;
}