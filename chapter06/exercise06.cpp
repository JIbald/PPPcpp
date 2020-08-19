#include "../std_lib_facilities.h"

vector <std::string> conjunctions {"and", "or", "but"};
vector <std::string> nouns {"birds", "fish", "C++"};
vector <std::string> verbs {"rules", "fly", "swim"};
vector <std::string> articles {"the", "a"};

void display_str_vec ( vector <std::string> vec )
{
    if ( vec.empty() )
    {
        std::cout << "EMPTY VECTOR" << std::endl;
    }
    else
    {
        for (std::string i : vec)
        {
            std::cout << i << std::endl;
        }
    }
}

bool is_conjunction ( std::string word )
{
    for (int i = 0; i < conjunctions.size(); ++i)
    {
        if ( conjunctions[i] == word )
        {
            return true;
        }
    }
    error("conjunction not in databank");
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
    error("noun not in databank");
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
    error("verb not in databank");
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
try
{
    std::string sentence {" "};
    vector <std::string> input {};
    while (std::cin >> sentence)
    {
        input.push_back(sentence);
    }
    
    display_str_vec(input);
    return 0;
}
catch (exception& e)
{
    cerr << "error: " << e.what() << '\n';
    keep_window_open();
    return 1;
}
catch (...)
{
    cerr << "Oops: unknown exception!\n";
    keep_window_open();
    return 2;
}