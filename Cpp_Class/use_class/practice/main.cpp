#include <iostream>
using namespace std;

#ifdef SHOW_EXERCISE7_H
#include "exercise.h"

int main()
{
    Complex a(3.0, 4.0);
    Complex c;
    cout << "Enter a complex number (q to quit):\n";
    while (cin >> c)
    {
        cout << "c is " << c << '\n';
        cout << "complex conjugate is " << ~c << '\n';
        cout << "a is " << a << '\n';
        cout << "a + c is " << a + c << '\n';
        cout << "a - c is " << a - c << '\n';
        cout << "a * c is " << a * c << '\n';
        cout << "2 * c is " << 2 * c << '\n';
        cout << "Enter a complex number (q to quit):\n";
    }
    cout << "Done!\n";
    return 0;
}
#endif /*  SHOW_EXERCISE7_H  */


// int main(void)
// {
//     int a = 10;

//     int& lref = a;
//     int&& rref = 20;

//     cout << "l-value ref: " << lref << endl;
//     cout << "r-value ref: " << rref << endl;

//     lref = 100;
//     rref = 200;
//     cout << "l-value ref: " << lref << endl;
//     cout << "r-value ref: " << rref << endl;

//     int b = 99;
//     lref = b;
//     cout << "l-value ref: " << lref << endl;

//     //lref = rref;
//     //cout << "l-value ref: " << lref << endl;

//     //rref = lref;
//     //cout << "r-value ref: " << rref << endl;

//     int c = 111;
//     int&& test = c;
//     cout << "r-value ref: " << test << endl;

//     return 0;
// }


int main()
{
    //  OK
    //const int& lref = 100;
    //cout << "lref: " << lref << endl;

    //  ERROR
    //int a = 999;
    //int&& rref = a;
    //cout << "rref: " << rref << endl;

    return 0;
}