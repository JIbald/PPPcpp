#include <iostream>
#include <string>
#include <vector>

void display_vector (std::vector <int> vec)
{
    for ( int i : vec )
    {
        std::cout << "| " << i << " ";
    }
    std::cout << std::endl << std::endl;
}

int main()
{
    std::vector <int> possibilities {};

    //fill up the std::vector
    for ( int i = 1; i <= 100; ++i )
    {
        possibilities.push_back(i);
    }
    display_vector(possibilities);

    //delete all uneven numbers
    for ( int i = 0; i < possibilities.size(); ++i )
    {
        if ( possibilities[i] % 2 == 0 )
        {
            possibilities.erase(possibilities.begin() + (i-1) );
        }

    }
    display_vector(possibilities);

    //show numbers divideable by 4
    // for ( int i = 0; i < possibilities.size(); ++i )
    // {
    //     if ( possibilities[i] % 4 == 0)
    //     {
    //         possibilities.erase(possibilities.begin() + (i-1) );
    //     }
    // }
    // display_vector(possibilities);

    //show numbers NOT divideable by 4
    for ( int i = 0; i < possibilities.size(); ++i )
    {
        if ( possibilities[i] % 4 == 0 )
        {
            possibilities.erase(possibilities.begin() + i);
        }
    }
    display_vector(possibilities);

    return 0;
}