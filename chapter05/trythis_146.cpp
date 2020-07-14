#include "../std_lib_facilities.h"

int area(int length, int width)
{
    return length * width;
}

int framed_area(int x, int y)
{
    return area(x-2, y-2);
}



int main()
{
    int x{0}, y{0}, z{0};
    std::cin >> x >> y >> z;
    int area1 = area(x, y);
    if ( area1 <= 0 )
    {
        error("non-positive area");
    }
    int area2 = framed_area(1, z);
    int area3 = framed_area(y, z);
    double ratio = double(area1) / area3;

    std::cout << "area1: " << area1 << std::endl;
    std::cout << "area2: " << area2 << std::endl;
    std::cout << "area3: " << area3 << std::endl;
    std::cout << "ratio: " << ratio << std::endl;


    return 0;
}