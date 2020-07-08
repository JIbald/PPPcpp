#include "../std_lib_facilities.h"

int j_square (int val)
{
    int temp = val;
    for (int i = 1; i < val; i++)
    {
        temp += val;
        std::cout << temp << std::endl;
    }
    return temp;
}

int main()
{
    int val {0};
    std::cout << "enter a value to be squared: ";
    std::cin >> val;
    std::cout << std::endl;
    std::cout << val << " squared equals: " << j_square(val) << std::endl;
    return 0;
}