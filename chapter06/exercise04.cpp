#include "../std_lib_facilities.h"

class Name_value
{
public:
    std::string name;
    int num;
    Name_value()
    { }
};

bool is_double (vector <Name_value> vec, Name_value nv)
{
    for (Name_value i : vec)
    {
        if (i.name == nv.name )
        {
            std::cout << "name already taken" << std::endl;
            return true;
        }
    }
    return false;
}

int main()
{
    vector <Name_value> vec_name_val {};

    bool double_name { false }; //necessary to avoid 
    bool go { true };
    while ( go )
    {
        std::cout << "Enter a name and a number (seperated by whitespace)\n";
        std::cout << "entering a name twice terminates the program.\n";
        Name_value nv;
        std::cin >> nv.name >> nv.num;
        std::cout << std::endl;

        if ( nv.name != "NoName" && nv.num != 0 && !is_double(vec_name_val, nv) )
        {
            vec_name_val.push_back(nv);
        }
        else
        {
            std::cout << "NoName paired with 0 terminates the program." << std::endl;
            go = false;
        }
    }

    for ( Name_value i : vec_name_val )
    {
        std::cout << i.name << " : " << i.num << std::endl;
    }

    return 0;
}