//
// This is example code from Chapter 6.7 "Trying the second version" of
// "Software - Principles and Practice using C++" by Bjarne Stroustrup
//

/*
	This file is known as calculator02buggy.cpp

	I have inserted 5 errors that should cause this not to compile
	I have inserted 3 logic errors that should cause the program to give wrong results

	First try to find an remove the bugs without looking in the book.
	If that gets tedious, compare the code to that in the book (or posted source code)

	Happy hunting!

*/

#include "../std_lib_facilities.h"

//------------------------------------------------------------------------------

class Token 
{
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value 
    
    //constructor 1: make a Token from a char
    Token(char ch)    
        :kind(ch), value(0) 
    { }

    //constructor 2: make a Token from a char and a double
    Token(char ch, double val)
        :kind(ch), value(val) 
    { }
};

void print_token_mem(Token t);
//------------------------------------------------------------------------------

class Token_stream 
{
public: 
    Token_stream();   // make a Token_stream that reads from cin
    Token get();      // get a Token (get() is defined elsewhere)
    void putback(Token t);    // put a Token to a buffer Token-type variable
private:
    bool full;        // is there a Token in the buffer?
    Token buffer;     // here is where we keep a Token put back using putback()
};

//------------------------------------------------------------------------------

// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
    :full(false), buffer(0)    // no Token in buffer
{ }

//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
    if (full)
    {
        error("putback() into a already full buffer");   
    }
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}

//------------------------------------------------------------------------------

Token Token_stream::get()
{
    //executes if we have a Token in the buffer
    if (full) 
    {
        // remove token from buffer
        full=false;
        return buffer;
    } 

    //executes if we do not have a Token in the buffer
    char ch;
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) 
    {
        case '=':    // for "print"
        case 'x':    // for "quit"
        case '{': case '}': case '(': case ')': case '+': case '-': case '*': case '/': 
        {
            Token t_symbol{ ch };
            //DEBUG LINES
            std::cout << "GET() symbol case" << std::endl;
            print_token_mem(t_symbol);
            return t_symbol;   // let '#' represent "a number"
        }
        case '.':
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        {    
            cin.putback(ch);         // put digit back into the input stream //from std::istream::putback, not Token_stream::putback
            double val;
            cin >> val;              // read a floating-point number
            Token t_number( '#', val );
            //DEBUG LINES
            std::cout << "GET() number case" << std::endl;
            print_token_mem(t_number);
            return t_number;   // let '#' represent "a number"
        }
        default:
            std::cout << "GET()" << std::endl;
            error("Bad token");
            return Token('R', -1000);
    }
    return Token('R', -1000);
}

//------------------------------------------------------------------------------

Token_stream ts;        // provides get() and putback() 

//------------------------------------------------------------------------------

double expression();    // declaration so that primary() can call expression()

//------------------------------------------------------------------------------

// deal with numbers and parentheses
double primary()
{
    std::cout << "PRIMARY() GET()" << std::endl;
    Token t = ts.get();

    //DEBUG LINES
    std::cout << "PRIMARY()" << std::endl;
    print_token_mem(t);

    switch (t.kind) {
    case '{':   // handle '{' expression '}'
    {
        double d {expression()};
        t = ts.get();
        if (t.kind != '}')
        {
            error("'}' expected");
        }
        return d;
        
    }
    case '(':    // handle '(' expression ')'
    {    
        double d = expression();
        t = ts.get();
        if (t.kind != ')') 
        {
            error("')' expected"); // might need "no expression within parenthesis, empty ()"
        }
        return d;
    }
    case '#':            // we use '#' to represent a number
        return t.value;  // return the number's value
    default:
        error("primary expected");
        return -1000;
    }
    return -1000;
}

//------------------------------------------------------------------------------

// deal with *, /, and %
double term()
{
    double left = primary();
    std::cout << "LEFT: " << left << std::endl;
    Token t = ts.get();        // get the next token from token stream
    
    //DEBUG LINES
    std::cout << "TERM()" << std::endl;
    print_token_mem(t);

    while(true) {
        switch (t.kind) {
        case '*':
        {
            left *= primary();
            t = ts.get();
            // originally no break
            break;
        }
        case '/':
        {    
            double d = primary();
            if (d == 0) 
            {
                error("divide by zero");
            }
            left /= d; 
            t = ts.get();
            //return left; //pretty sure no return here, we check as long as we can't multiply or divide and if not so we put it back to stream and let either expression or primary handle this
            break;
        }
        default: 
            ts.putback(t);     // put t back into the token stream
            return left;
        }
    }
}

//------------------------------------------------------------------------------

// deal with + and -
double expression()
{
    double left = term();      // read and evaluate a Term
    std::cout << "EXPRESSION() GET()" << std::endl;
    Token t = ts.get();        // get the next token from token stream
    
    //DEBUG LINES
    std::cout << "EXPRESSION()" << std::endl;
    print_token_mem(t);

    while(true) {    
        switch(t.kind) {
        case '+':
            left += term();    // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term();    // evaluate Term and subtract
            t = ts.get();
            break;
        default: 
            ts.putback(t);     // put t back into the token stream
            return left;       // finally: no more + or -: return the answer
        }
    }
}

//------------------------------------------------------------------------------
//print a token's members for debugging
void print_token_mem(Token t)
{
    std::cout << "Token kind: " << t.kind << std::endl;
    std::cout << "Token value: " << t.value << std::endl;
    std::cout << std::endl;
}

int main()
try
{
    std::cout << "Welcome to our simple calculator." << std::endl;
    std::cout << "Please enter expressions using floating-point numbers." << std::endl;
    std::cout << "Available operations: (...), *, /, +, -" << std::endl;
    std::cout << "print by ending your input with \"=\"" << std::endl;
    std::cout << "exit by ending with an \"x\"" << std::endl;

    double result {0};
    while (cin) 
    {
        Token t = ts.get();
        std::cout << "MAIN()" << std::endl;
        print_token_mem(t); //DEBUG

        if (t.kind == 'q') 
        {
            break; // 'q' for quit
        }
        if (t.kind == '=')      // '=' for "print now"
        {
            //cout << "=" << t.value << '\n';
            cout << "=" << result << '\n';
        }
        else
        {
            ts.putback(t);
        }
        //t.value = expression();
        result = expression();
    }
	keep_window_open();
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

//------------------------------------------------------------------------------