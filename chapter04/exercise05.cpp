#include "../std_lib_facilities.h"

int main()
{
    double a {0};
    double b {0};
    char operation {' '};

    std::cout << "enter two numbers and either +, -, *, or /. (seperated by whitespace):";
    std::cin >> a >> b >> operation;
    std::cout << std::endl;

    switch(operation)
    {
        case '+':
            std::cout << "the sum of " << a << " and " << b << " is " << a+b << std::endl;
            break;

        case '-':
            std::cout << "the difference between " << a << " and " << b << " is " << a-b << std::endl;
            break;

        case '*':
            std::cout << "the product of " << a << " and " << b << " is " << a*b << std::endl;
            break;

        case '/':
            std::cout << "the quotient of " << a << " and " << b << " is " << a/b << std::endl;
            break;

        default:
            std::cout << "unfortunately this operation is unknown." << std::endl;
            break;
    }

    return 0;
}