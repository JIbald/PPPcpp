#include "../std_lib_facilities.h"



int main()
{
    //a 32 bit integer can hold a number as large as 2,147,483,647
    //ergo it is sufficient to work with them to solve this exercise's question.
    int num_ricecorn {1};

    while ( num_ricecorn < 100000)
    {
        for ( int square = 1; square <= 64; ++square )
        {
            num_ricecorn *= 2;
            if ( num_ricecorn >= 1000 )
            {
                std::cout << "on the " << square << "th square we have at least 1000 ricecorns. (" << num_ricecorn << ")" << std::endl;
            }
            if ( num_ricecorn >= 10000 )
            {
                std::cout << "on the " << square << "th square we have at least 10.000 ricecorns. (" << num_ricecorn << ")" << std::endl;
            }
        }
    }

    return 0;
}