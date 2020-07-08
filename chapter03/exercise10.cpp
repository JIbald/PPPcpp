#include "../std_lib_facilities.h"
#include <string>


int main()
{
    std::string operation {" "};
    double operand1 {0.0};
    double operand2 {0.0};
    double result {0.0};

    std::cout << "enter an operation followed by two operands ( serperated by whitespace ): ";
    std::cin >> operation >> operand1 >> operand2;

    if(operation == "+" || operation == "plus")
    {
        result = operand1 + operand2;
    }
    else if (operation == "-" || operation == "minus")
    {
        result = operand1 - operand2;
    }
    else if (operation == "*" || operation == "mul")
    {
        result = operand1 * operand2;
    }
    else if (operation == "/" || operation == "div")
    {
        if (operand2 == 0)
        {
            std::cout << "do not divide by zero." << std::endl;
        }
        
        result = operand1 / operand2;
    }
    else
    {
        std::cout << "sorry, I don't know this operator." << std::endl;
    }
    
    std::cout << "result: " << result << std::endl;    

    return 0;
}