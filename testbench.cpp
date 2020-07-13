#include <iostream>
#include <string>
#include <vector>
#include <cmath>

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

    int n {100};
    std::vector <int> vec {};
    for ( int i = 2; i <= n; ++i)
    {
        vec.push_back(i);
    }
    //display_vector(vec);

    int counter1 {0};
    for ( int i = 0; i <= std::sqrt(n); ++i )
    {
        ++counter1;
        std::cout << "==========OUTER: " << counter1 << " ==========" << " i: " << i << " ==========" << std::endl;

        int counter2 {0};
        for ( int j = i + 1; j < vec.size(); ++j )
        {
            ++counter2;
            std::cout << "==========INNER: " << counter2 << " ==========" << " j: " << j << " ==========" << std::endl;
            if ( vec[j] % vec[i] == 0 )
            {
                vec.erase(vec.begin() + j);
            }
            display_vector(vec);
        }
    }

    return 0;
}