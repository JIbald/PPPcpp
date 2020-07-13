#include "../std_lib_facilities.h"

void display_vector (vector <int> vec)
{
    for ( int i : vec )
    {
        std::cout << "| " << i << " ";
    }
    std::cout << std::endl << std::endl;
}

int mode_in_vec (vector <int> vec) //finds first int occuring the most. Won't say if there's more than one. not ver yefficient :(
{
    vector <int> modes {};
    int mode {-1};
    int occurence {0};
    int max {0};
    for ( int i {0}; i < vec.size(); ++i)
    {
        occurence = 0;
        for ( int j {0}; j < vec.size(); ++j)
        {
            if ( vec[j] == vec[i] )
            {
                ++occurence;
            }
        }
        if ( occurence > max )
        {
            max = occurence;
            mode = vec[i];
        }
        // else if ( occurence == max )
        // {
        //     std::cout << vec[i] << " occurs as often as " << mode << " ,which will be returned." << std::endl;
        // }
    }
    std::cout << "mode " << mode << " appears " << max << " times." << std::endl;
    return mode;
}

int main()
{
    std::cin.clear();
    vector <int> vec {};
    int num {0};
    while (std::cin >> num)
    {
        vec.push_back(num);
    }
    display_vector(vec);

    int mode = mode_in_vec(vec);

    std::cout << mode << std::endl;

    return 0;
}
