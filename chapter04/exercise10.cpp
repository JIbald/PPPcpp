#include "../std_lib_facilities.h"

int main()
{
    vector <std::string> rps {"rock", "paper", "scissors"};
    int num {0};
    std::string sys_guess {" "};
    std::string input {" "};
    bool gameover {false};

    while(!gameover)
    {
        std::cout << "rock paper scissors: ";
        std::cin >> input;
        std::cout << std::endl;

        std::cout << "put in a number between 1 and 3:";
        std::cin >> num;
        std::cout << std::endl;

        sys_guess = rps[num - 1];

        //debug loop
        for ( int i = 0; i < rps.size(); ++i)
        {
            std::cout << rps[i] << " ";
        }
        std::cout << std::endl;
        //debug line
        std::cout << sys_guess << std::endl;

        if ( input == sys_guess )
        {
            std::cout << "a tie !" << std::endl;
        }
        else if ( (input == "rock" && sys_guess == "scissors") || (input == "paper" && sys_guess == "rock") || (input == "scissors" && sys_guess == "paper") )
        {
            std::cout << "system: " << sys_guess << "\tyou: " << input;
            std::cout << "you win." << std::endl;
        }
        else if ( (input == "rock" && sys_guess == "paper") || (input == "paper" && sys_guess == "rock") || (input == "scissors" && sys_guess == "rock") )
        {
            std::cout << "system: " << sys_guess << "\tyou: " << input << std::endl;
            std::cout << "you loose." << std::endl;
        }

        std::string temp {sys_guess};
        rps.erase(rps.begin() + (num - 1));
        rps.push_back(temp);

        //debug loop
        for ( int i = 0; i < rps.size(); ++i)
        {
            std::cout << rps[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "play again?";
        std::cin >> input;
        if( input != "y" && input != "Y")
        {
            gameover = true;
        }
    }

    return 0;
}