#include "../std_lib_facilities.h"

int main()
{
    vector <std::string> words;

    for(std::string temp; std::cin >> temp;)
    {
        words.push_back(temp);
    }

    std::cout << "number of words: " << words.size() << std::endl;

    sort(words);

    for (int i = 0; i < words.size(); i++)
    {
        if(i == 0 || words[i-1] != words[i])
        {
            std::cout << words[i] << "    ";
        }
    }
    std::cout << std::endl;
    

    return 0;
}