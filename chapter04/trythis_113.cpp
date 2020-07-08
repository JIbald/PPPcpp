#include "../std_lib_facilities.h"

int main()
{
    //I used the ascii chart for this and jumped over the symbols.
    //the iterator variable ( i ) loops accordingly to the chart.
    // https://www.commfront.com/pages/ascii-chart
    for (int i = 65; i < 123; i++)
    {
        //this clearly violates what Bjarne Stroustrup is recommending,
        //since it so profoundly ignores that you shouldn't modifiy your iterator within the body.
        //you could do this with just two for loops to avoid such violation.
        //I let this be controversial :)
        if(i == 91)
        {
            i += 6;
        }
        std::cout << char(i) << std::endl;
    }
    

    return 0;
}