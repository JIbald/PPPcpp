#include "../std_lib_facilities.h"

int main()
{
    char initial_c {'a'};
    int i {0};

    while(i < 27)
    {
        std::cout << char(initial_c + i) << "    " << int(initial_c + i) << std::endl;
        ++i;
    }

    return 0;
}