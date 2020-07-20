#include "../std_lib_facilities.h"

struct week
{
    vector <int> mondays {};
    vector <int> tuesdays {};
    vector <int> wednesdays {};
    vector <int> thursdays {};
    vector <int> fridays {};
    vector <int> saturdays {};
    vector <int> sundays {};
    int reject {0};
};

void read_day_val (std::string day, int val, week &result)
{
    if( day == "mon" || day == "monday")
    {
        result.mondays.push_back(val);
    }
    else if ( day == "tue" || day == "tuesday" )
    {
        result.tuesdays.push_back(val);
    }
    else if ( day == "wed" || day == "wednesday" )
    {
        result.wednesdays.push_back(val);
    }
    else if ( day == "thur" || day == "thursday" )
    {
        result.thursdays.push_back(val);
    }
    else if ( day == "fri" || day == "friday" )
    {
        result.fridays.push_back(val);
    }
    else if ( day == "sat" || day == "saturday" )
    {
        result.saturdays.push_back(val);
    }
    else if ( day == "sun" || day == "sunday" )
    {
        result.sundays.push_back(val);
    }
    else if ( day == "q")
    {
        std::cout << "end of input" << std::endl;
    }
    else
    {
        ++result.reject;
    }
}

int vec_sum ( vector <int> vec )
{
    int sum {0};
    for( int i {0}; i < vec.size(); ++i )
    {
        sum += vec[i];
    }
    return sum;
}

void print_day ( std::string day, vector <int> weekday)
{
    std::cout << day << " ";
    for( int i {0}; i < weekday.size(); ++i )
    {
        std::cout << "| " << weekday[i] << " ";
    }
    std::cout << "|" << " sum: " << vec_sum(weekday) << std::endl;
}

void print_week (week week)
{
    print_day("monday", week.mondays);
    print_day("tuesday", week.tuesdays);
    print_day("wednesday", week.wednesdays);
    print_day("thursday", week.thursdays);
    print_day("friday", week.fridays);
    print_day("saturday", week.saturdays);
    print_day("sunday", week.sundays);
    std::cout << "rejected: " << week.reject << std::endl;
}

int main()
{
    std::cout << "input a day (mon/monday, ...,q ends input) and a value (interger) (separated by whitespace): ";
    std::string input_day {" "};
    int input_val {0};
    week result_week;
    // result_week.mondays.push_back(476);
    // print_day("monday", result_week.mondays);
    bool run {true};
    while (run)
    {
        std::cin >> input_day >> input_val;
        if(input_day == "q")
        {
            run = false;
        }
        read_day_val(input_day, input_val, result_week);
    }
    print_week(result_week);

    return 0;
}