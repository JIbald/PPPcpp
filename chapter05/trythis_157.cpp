//i scribbled something and then did this:
#include "../std_lib_facilities.h"

double hexagon_area (double side_length)
{
    return ( sqrt(3) * side_length * side_length * 6 ) / 4;
}

int main()
{
    double side {2.0};
    std::cout << hexagon_area(side) << std::endl;

    return 0;
}