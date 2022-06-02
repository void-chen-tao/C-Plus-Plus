#include <iostream>
using std::cout;
#include "bad-string.h"

void callme1(BadString&);
void callme2(BadString);


int main(void)
{
    using std::endl;
    {
        cout << "Starting an inner block.\n";
        BadString headline1("Celery Stalks at Midnight");
        BadString headline2("Lettuce Prey");
        BadString sports("Spinach Leaves Bowl for Dollars");
        cout << "headline1: " << headline1 << endl;
        cout << "headline2: " << headline2 << endl;
        cout << "sports: " << sports << endl;

        callme1(headline1);
        cout << "headline1: " << headline1 << endl;
        callme2(headline2);
        cout << "headline2: " << headline2 << endl;
    }
}


void callme1(BadString& rsb)
{
    cout << "String passed by reference:\n";
    cout << "\t\"" << rsb << "\"\n";
}

void callme2(BadString sb)
{
    cout << "String passed by value:\n";
    cout << "\t\"" << sb << "\"\n";
}