#include "../std_lib_facilities.h"

int main()
{
    int int_ricecorn {1};
    double double_ricecorn {1};
    int square {1};

    while ( square < 64 )
    {
        for (square = 1; square <= 64; ++square )
        {
            int_ricecorn *= 2;
            double_ricecorn *= 2;
            
            std::cout << "square:\t" << square << "\tint:\t" << int_ricecorn << std::endl;
            std::cout << "square:\t" << square << "\tdouble:\t" << double_ricecorn << std::endl;
        }
    }

    return 0;
}