//extend the Screen class to include move(), set(), and display()
#include <iostream>
#include <string>
#include <cstdlib> // EXIT_FAILURE 
using namespace std;

class Screen
{
public:
    typedef string::size_type index;
private:
    string contents;
    index cursor;
    index height, width;
    void do_display(ostream& os) const;
public:
    char get() const {return contents[cursor]; }
    inline char get(index ht, index wd) const;
    index get_cursor() const;
    Screen(index hght, index wdth, const string &cntnts);
    // add 3 member funcs
    Screen& move(index r, index c);
    Screen& set(char);
    // if Screen obj is const, cannot use display to show (because const obj can only use const func)
    Screen& display(ostream &os);
    // add this func overload to solve the above func's problem
    const Screen& display(ostream &os) const;
};

//Screen::Screen(index hght, index wdth, const string &cntnts): contents(cntnts), cursor(0), height(hght), width(wdth){ }
// NOTE a better constructor is as follows (do not need to give full string of the screen)
Screen::Screen(index hght, index wdth, const string &cntnts = ""): cursor(0), height(hght), width(wdth)
{ 
    // set the content of the screen as spaces ' '
    contents.assign(hght * wdth, ' ');
    // use parameter string to set screen
    if(cntnts.size() != 0)
    {
        contents.replace(0, cntnts.size(), cntnts);
    }
}

void Screen::do_display(ostream& os) const
{
    string::size_type index = 0;
    while(index != contents.size())
    {
        os << contents[index];
        if((index + 1) % width == 0)
        { os << '\n'; }
        ++index;
    }
}


char Screen::get(index r, index c) const
{
    index row = r * width;
    return contents[row + c];
}

// NOTE the return type is defined in Screen so have such a scoping 
inline Screen::index Screen::get_cursor() const
{
    return cursor;
}

// add definition of 3 member funcs
Screen& Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

Screen& Screen::move(index r, index c)
{
    // add this to avoid exceeding border
    if( r >= height || c >= width)
    {
        cerr << "invalid row or column" << endl;
        throw EXIT_FAILURE;
    }

    // original code
    index row = r * width;
    cursor = row + c;
    return *this;
}

/*
Screen& Screen::display(ostream &os)
{
    //os << contents;
    //return *this;
    //0622 Better display according to pre-set height and width
    string::size_type index = 0;
    while(index != contents.size())
    {
        os << contents[index];
        if((index + 1) % width == 0)
        { os << '\n'; }
        ++index;
    }
    return *this;
}

const Screen& Screen::display(ostream &os) const
{
    //os << contents;
    //return *this;
    //0622 Better display according to pre-set height and width
    string::size_type index = 0;
    while(index != contents.size())
    {
        os << contents[index];
        if((index + 1) % width == 0)
        { os << '\n'; }
        ++index;
    }
    return *this;
}*/

// since the above two funcs have exactly the same func body, to reduce code duplication, we define a do_display func to fulfill the real display work, and the two overloaded display function can call do_play. We can define do_play as private (since we do not want the outside to call it)

//NOTE do_display must be defined as const, because const func can only call const func, while non-const func can also call const func
Screen& Screen::display(ostream& os)
{
    //ostream& os1 = os;
    //do_display(os1);
    do_display(os);
    return *this;
}

const Screen& Screen::display(ostream& os) const
{
    //ostream& os1 = os;
    //do_display(os1);
    do_display(os);
    return *this;
}

int main()
{
    //create according to the height, width and content value to create screen
    // NOTE '\n' also counts as a char
    //(1) call const object
    const Screen myScreen(5, 7, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    myScreen.display(cout);
    //(2) call non-const object
    Screen myScreen2(5, 7, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab");
    // move cursor to a fixed point, set char and show screen content
    myScreen2.move(3, 3).set('#').display(cout);
    return 0;
}
