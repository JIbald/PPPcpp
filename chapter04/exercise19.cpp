#include "../std_lib_facilities.h"

int main()
{
    vector <std::string> names {};
    std::string name {" "};

    vector <int> nums {};
    int num {0};

    bool double_name { false }; //necessary to avoid 
    bool go { true };
    while ( go )
    {
        std::cout << "Enter a name and a number (seperated by whitespace)\n";
        std::cout << "entering a name twice terminates the program.\n";
        std::cin >> name >> num;
        std::cout << std::endl;

        for ( std::string i : names )
        {
            if ( i == name )
            {
                std::cout << "entering a name twice terminates the program." << std::endl;
                double_name = true;
                go = false;
            }
        }

        if ( name != "NoName" && num != 0 && double_name == false)
        {
            names.push_back(name);
            nums.push_back(num);
        }
        else
        {
            std::cout << "NoName paired with 0 terminates the program." << std::endl;
            go = false;
        }
    }

    for ( int i = 0; i < names.size(); ++i )
    {
        std::cout << names[i] << " : " << nums[i] << std::endl;
    }

    return 0;
}