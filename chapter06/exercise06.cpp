#include "../std_lib_facilities.h"
#include <iomanip>

//global vectors for our word library
vector <std::string> articles {"the", "a"};
vector <std::string> nouns {"birds", "fish", "C++"};
vector <std::string> verbs {"rules", "fly", "swim"};
vector <std::string> conjunctions {"and", "or", "but"};

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

bool is_article ( std::string word )
{
    for (int i = 0; i < articles.size(); ++i)
    {
        if ( articles[i] == word )
        {
            return true;
        }
    }
    //error("article not in databank");
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
    //error("noun not in databank");
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
    //error("verb not in databank");
    return false;
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
    //error("conjunction not in databank");
    return false;
}

//check if (article + noun + verb) OR (noun + verb)
bool is_anv()
{
    string str0;
    std::cin >> str0;
    string str1;
    std::cin >> str1;

    //starts with article
    if ( is_article(str0) && is_noun(str1))
    {
        string str2;
        std::cin >> str2;
        if ( !is_verb(str2) )
        {
            return false;
        }
        return true;
    }
    //starts without article
    else if ( is_noun(str0) )
    {
        if ( !is_verb(str1) )
        {
            return false;
        }
        return true;
    }
    //starts with neither
    else
    {
        return false;
    }
}

bool is_sentence()
{
    //if sentence isn't starting with (article) + noun + verb
    if ( !is_anv() )
    {
        return false;
    }
    string str0;
    std::cin >> str0;
    //if next word is a conjunction
    //it must inevitably be followed by another (a)nv combination
    if ( is_conjunction(str0) && is_anv() )
    {
        string str1;
        std::cin >> str1;
        //theoretically this is false since we can only connect two anv + conjunction + anv + "." and not more
        if ( str1 == "." )
        {
            return true;
        }
        return false;
    }
    else if ( str0 == "." )
    {
        return true;
    }
    return false;
}

int main()
try
{
    std::cout << std::boolalpha;
    bool check = is_sentence();
    std::cout << check << std::endl;
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