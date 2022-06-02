#include <cstring>
#include "bad-string.h"

using std::cout;

//  initializing static class member
int BadString::num_strings = 0;

//  class methods
//  construct badstring from C string
BadString::BadString(const char* s)
{
    len = std::strlen(s);           //  set size
    str = new char[len+1];          //  allot storage
    std::strcpy(str, s);            //  initialize pointer
    ++num_strings;                  //  increase count
    cout << num_strings << ": \"" << str
         << "\" object created\n";  //  create message
}

//  default construct
BadString::BadString()
{
    len = 4;
    str = new char[4];
    std::strcpy(str, "C++");
    ++num_strings;
    cout << num_strings << ": \"" << str
         << "\" default object created\n";
}

BadString::~BadString()           //    necessary destructor
{
    cout << "\"" << str << "\" object deleted, ";
    --num_strings;
    cout << num_strings << " left\n";
    delete [] str;
}

std::ostream& operator<<(std::ostream& os, const BadString& st)
{
    os << st.str;
    return os;
}