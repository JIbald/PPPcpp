#include "../std_lib_facilities.h"

int main()
{
    std::string disliked001 {"earthquakes"};
    std::string disliked002 {"hurricanes"}; //I was torn whether this good or bad to (not) include.
    std::string disliked003 {"fishchips"};
    
    vector <std::string> words {};

    for(std::string temp; std::cin >> temp;)
    {
        words.push_back(temp);
    }

    //sort(words); //just out of interest.

    std::cout << " ";
    for( std::string i : words )
    {
        if (i == disliked001)
        {
            i = "ICECREAM";
        }
        else if ( i == disliked002 )
        {
            i = "adore";
        }
        else if (i == disliked003)
        {
            i = "marshmallows";
        }
        
        std::cout << i << " |";
    }
    std::cout << std::endl;
}