#include "../std_lib_facilities.h"

int main()
{
    vector <std::string> num_words {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    vector <std::string> num_digits {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };
    std::string input;
    std::cout << "input a number in either digit or spelled out: ";
    std::cin >> input;

    bool found {false};

    while ( !found )
    {
        for ( int i = 0; i < num_words.size(); ++i )
        {
            if ( num_words[i] == input )
            {
                std::cout << i << std::endl;
                found = true;
            }
        }

        for ( int i = 0; i < num_digits.size(); ++i )
        {
            if ( num_digits[i] == input )
            {
                std::cout << num_words[i] << std::endl;
                found = true;
            }
        }
    }



    return 0;
}