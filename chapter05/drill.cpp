#include "../std_lib_facilities.h"

int main()
{
    try
    {
        //snippet start
        int i = 0;
        while ( i < 10 )
        {
            ++i
        }
        //snippet end

        keep_window_open();
        return 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "error: " << e.what() << '\n';
        keep_window_open();
        return 1;
    }
    catch(...)
    {
        std::cerr << "Oops: unknown exception!\n";
        keep_window_open();
        return 2;
    }
    

    return 0;
}