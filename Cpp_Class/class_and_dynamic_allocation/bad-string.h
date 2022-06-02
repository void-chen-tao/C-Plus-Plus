//  bad string -- flawed string class definition
#include <iostream>
#ifndef BAD_STRING_H
#define BAD_STRING_H

class BadString
{
private:
    char* str;                      //  pointer to string
    int len;                        //  length of string
    static int num_strings;         //  number of objects
public:
    BadString(const char* s);       //  char* type constructor
    BadString();                    //  default constructor
    ~BadString();                   //  destructor
    //  friend function
    friend std::ostream& operator<<(std::ostream& os, const BadString& st);
};

#endif /* BAD_STRING_H */