#include "../std_lib_facilities.h"

void display_vector (vector <std::string> vec)
{
    for ( std::string i : vec )
    {
        std::cout << "| " << i << " ";
    }
    std::cout << std::endl << std::endl;
}

std::string get_min ( vector <std::string> vec )
{
    std::string min {vec[0]};
    for ( string i : vec )
    {
        if ( i < min )
        {
            min = i;
        }
    }
    return min;
}

std::string get_max ( vector <std::string> vec )
{
    std::string max {vec[0]};
    for ( std::string i : vec )
    {
        if ( i > max )
        {
            max = i;
        }
    }
    return max;
}

std::string get_mode ( vector <std::string> vec )
{
    std::sort(vec.begin(),vec.end());
    std::string mode_cdt = vec[0];
    int mode_cdt_ctr = 1;
    std::string mode = vec[0];
    int mode_ctr = 1;

    for ( int i = 1; i < vec.size(); ++i ) 
    {
        if ( vec[i]==mode_cdt ) 
        {
            ++mode_cdt_ctr;
            if ( mode_cdt_ctr > mode_ctr ) 
            {
                mode = mode_cdt;
                mode_ctr = mode_cdt_ctr;
            }
        }
        else 
        {
            mode_cdt = vec[i];
            mode_cdt_ctr = 1;
        }
    }
    return mode;
}


int main()
{
    vector <string> string_vec {};
    std::string input;
    while ( std::cin >> input )
    {
        string_vec.push_back(input);
    }

    display_vector(string_vec);

    std::cout << "the min: " << get_min(string_vec) << std::endl;
    std::cout << "the max: " << get_max(string_vec) << std::endl;
    std::cout << "the mode: " << get_mode(string_vec) << std::endl;
    display_vector(string_vec);

    return 0;
}