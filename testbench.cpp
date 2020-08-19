#include "std_lib_facilities.h"

vector <std::string> conjunctions {"and", "or", "but"};
vector <std::string> nouns {"birds", "fish", "C++"};
vector <std::string> verbs {"rules", "fly", "swim"};
vector <std::string> articles {"the", "a"};

bool is_conjunction ( std::string word )
{
    for (int i = 0; i < conjunctions.size(); ++i)
    {
        if ( conjunctions[i] == word )
        {
            return true;
        }
    }
    return false;
}

bool is_noun ( std::string word )
{
    for (int i = 0; i < nouns.size(); ++i)
    {
        if ( nouns[i] == word )
        {
            return true;
        }
    }
    return false;
}

bool is_verb ( std::string word )
{
    for (int i = 0; i < verbs.size(); ++i)
    {
        if ( verbs[i] == word )
        {
            return true;
        }
    }
    return false;
}

bool is_article ( std::string word )
{
    for (int i = 0; i < articles.size(); ++i)
    {
        if ( articles[i] == word )
        {
            return true;
        }
    }
    return false;
}

int main()
{
    std::string sentence {""};
    std::cin >> sentence;
    std::cout << "your input: " << sentence << std::endl;
    if ( is_article(sentence) )
    {
        std::cout << "works" << std::endl;
    }
    else
    {
        std::cout << "fails" << std::endl;
    }
    
    return 0;
}