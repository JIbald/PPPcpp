#include "std_lib_facilities.h"

void display_intvector (vector <int> vec)
{
    //pre-condition
    //vector can't be empty
    if(vec.empty() )
    {
        error("display_vector() pre-condition");
    }
    for( int i : vec )
    {
        std::cout << "| " << i << " ";
    }
    std::cout << "|" << std::endl;
}

int main()
{
    // vector <int> vec {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // display_intvector(vec);

    // vec.erase(vec.begin()+4, vec.begin()+7);
    // display_intvector(vec);

    // vec.insert(vec.begin()+4, 100);
    // display_intvector(vec);

    vector <int> vec1 {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    display_intvector(vec1);
    double product {0};

    for( int i {0}; i < vec1.size(); ++i)
    {
        if(vec1[i] == 7)
        {
            product = vec1[i-1] * vec1[i+1];
            vec1.erase(vec1.begin()+(i-1), vec1.begin()+(i+2));
            vec1.insert(vec1.begin()+ (i-1), product);
        }
    }
    display_intvector(vec1);
    std::cout << product << std::endl;

    return 0;
}