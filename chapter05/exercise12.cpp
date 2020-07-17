#include "std_lib_facilities.h"
#include <stdlib.h>
#include <time.h>

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

//create a vector with n random entries out of an int seed
vector <int> int_to_vec (int n, int seed)
{
    srand( time(NULL) );
    vector <int> random {};
    for( int i {0}; i < n; ++i )
    {
        random.push_back( rand()%seed );
    }
    return random;
}

//check if there are multiple of the same entry
bool same_entry (vector <int> vec)
{
    sort(vec);
    for( int i {1}; i < vec.size(); ++i )
    {
        if( vec[i] == vec[i - 1] )
        {
            return true;
        }
    }
    return false;
}

//make each vector entry different
vector <int> diff_vec (vector <int> vec)
{
    // srand( time(NULL) );
    // vector <int> solution { rand()%n, rand()%n, rand()%n, rand()%n };
    //check that each entry is different
    for( int i {0}; i < vec.size(); ++i )
    {
        for( int j {i + 1}; j < vec.size(); ++j )
        {
            if( vec[i] == vec[j] )
            {
                ++vec[j];
            }
        }
    }
    return vec;
}

//check for bulls and cows
struct bulls_cows
{
    int bulls {0};
    int cows {0};
};
bulls_cows count_bulls_cows ( vector <int> solution, vector <int> guess )
{
    bulls_cows number {0, 0};
    vector <char> vec_bulls (4, 'n');
    vector <char> vec_cows (4, 'n');
    //check for bulls:
    for( int i {0}; i < solution.size(); ++i )
    {
        if( guess[i] == solution [i] )
        {
            ++number.bulls;
            vec_bulls[i] = 'y';
        }
    }

    //check for cows:
    for( int i = 0; i < solution.size(); ++i )
    {
        if( vec_bulls[i] == 'n' )
        {
            for( int j = 0; j < solution.size(); ++j )
            {
                if( vec_bulls[j] == 'n' && vec_cows[j] == 'n' && solution[i] == guess[j] )
                {
                    ++number.cows;
                    vec_cows[j] = 'y';
                }
            }
        }
    }
    return number;
}

int main()
{
    std::cout << "welcome to bulls & cows (rules on page 171)" << std::endl;
    std::cout << "first, let's type in a difficulty (10 upwards in increments of 1 is reccomended)" << std::endl;
    int seed {0};
    std::cin >> seed;
    int amount {4}; //4 numbers to guess
    bulls_cows count {0, 0};
    vector <int> guess {};
    vector <int> solution {};
    int input {0};
    bool run {true};
    char state {'1'};
    while( run )
    {
        switch(state)
        {
            case '1': //create a vector with 4 unique random numbers based on chosen difficulty
                //std::cout << "case 1: " << std::endl;
                solution = { int_to_vec(amount, seed) };
                if( same_entry(solution) )
                {
                    solution = diff_vec(solution);
                }
                state = '2';
                break;

            case '2': //prompt user to type in his guess and store it in vector
                //std::cout << "case 2: " << std::endl;
                std::cout << "type in four integers (separated by whitespace): ";
                while(std::cin >> input)
                {
                    guess.push_back(input);
                }
                std::cout << std::endl;
                std::cin.clear();
                std::cin.ignore();
                state = '3';
                break;

            case '3': // check how many bulls and cows there are, show user
                //std::cout << "case 3: " << std::endl;
                count = count_bulls_cows(solution, guess);
                std::cout << "bulls: " << count.bulls << std::endl;
                std::cout << "cows: " << count.cows << std::endl;
                state = '4';
                break;

            case '4': //check winning condition
                //std::cout << "case 4: " << std::endl;
                if( count.bulls == amount )
                {
                    state = 'w';
                }
                else
                {
                    state = '5';
                }
                break;

            case '5': //reset the guess vector for new input
                guess.erase(guess.begin(), guess.end() );
                //bulls and cows count gets overwritten in case 3
                state = '2';
                break;

            case 'w':
                std::cout << "Congratulations, you won!" << std::endl;
                std::cout << "want to play again ? (y/n)" << std::endl;
                char answer {' '};
                std::cin >> answer;
                if( answer == 'y' || answer == 'Y' )
                {
                    state = '1';
                }
                else
                {
                    state = 'q';
                }
                break;

            case 'q':
            case 'Q':
                std::cout << "Goodbye." << std::endl;
                run = false;
                break;

            default:
                std::cout << "default: " << std::endl;
        }
    }

    return 0;
}