#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::vector <std::string> vec {"X1", "X2", "X3", "X4"};
    std::cout << vec[vec.size() / 2] << std::endl;

    return 0;
}