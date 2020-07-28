#include "../std_lib_facilities.h"

class Token
{
public:
    char kind;
    double value;
    Token(char c)
        :kind(c), value(0) { }
    Token(char c, double val)
        :kind(c), value(val) { }
};

class Token_Stream
{
public:
    Token get();
    void putback(Token t);
private:
    bool full {false};
    Token buffer;
};

void Token_Stream::putback(Token t)
{
    if (full)
    {
        error("putback() called allthough buffer is already full.");
    }
    buffer = t;
    full = false;
}

Token Token_Stream::get()
{
    if(full)
    {
        full = false;
        return buffer;
    }
    char ch;
    std::cin >> ch;

    switch(ch)
    {
        case ';':
        case 'q':
        case '(': case ')': case '+': case '-': case '*': case '/':
        {
            return Token{ch};
        }
        case '.':
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        {
            std::cin.putback(ch);
            double val;
            std::cin >> val;
            return Token {'8', val};
        }
        default:
        {
            error("Bad token.");
        }
    }
}

Token_Stream ts;

double expression();

double primary()
{

}

double term()
{

}

double expression()
{
    double left = term();
    Token t = ts.get();
    while (true)
    {
        switch(t.kind)
        {
            case '+':
            {
                left += term();
                t = ts.get();
                break;
            }
            case '-':
            {
                left -= term();
                t = ts.get();
                break;
            }
        }
    }
}

int main()
{

    return 0;
}