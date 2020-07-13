#include "../std_lib_facilities.h"

int area (int length, int width)
{
    return length * width;
}

int main()
{
    int s1 = area(7; //error: expected ')' int s1 = area(7;
    int s2 = area(7) //error: no matching function for call to 'area' int s2 = area(7)
    Int s3 = area(7); //warning: missing terminating ' character [-Winvalid-pp-token]
    int s4 = area('7'); // supposed to be area('7) warning: missing terminating ' character [-Winvalid-pp-token] int s4 = area('7);int s4 = area('7);

    return 0;
}