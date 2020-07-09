#include "../std_lib_facilities.h"

int str_input_to_int (std::string input)
{
    vector <std::string> num_words {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    vector <std::string> num_digits {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };

    for ( int i = 0; i < num_words.size(); ++i )
    {
        if ( num_words[i] == input )
        {
            return i;
        }
    }

    for ( int i = 0; i < num_digits.size(); ++i )
    {
        if ( num_digits[i] == input )
        {
            return i;
        }
    }
    return -1;
}


int main()
{
    
    std::string input1;
    std::string input2;
    char operation {' '};

    std::cout << "enter two single digit numbers and either +, -, *, or / (seperated by whitespace):";
    std::cin >> input1 >> input2 >> operation;
    int a = str_input_to_int(input1);
    int b = str_input_to_int(input2);

    if ( a == -1 || b == -1 )
    {
        std::cout << "wrong input." << std::endl;
        operation = ' ';
    }

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