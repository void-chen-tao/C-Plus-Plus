#ifdef SHOW_EXERCISE7_H
/*
 *  7.复数由两个部分组成：实数和虚数。复数的一种书写方式是：(3.0， 4.0)。现在假设a=(A, Bi),c=(C, Di)
 *    加法：a+c=(A+C, (B+D)i)
 *    减法：a-c=(A-C, (B-D)i)
 *    乘法：a*c=(A*C-B*D, (A*D+B*C)i)
 *    乘法：x*c=(x*C, x*Di),其中x为实数
 *    共轭：~a=(A, -Bi)
 * 
 *    请定义一个复数类，以便下面的程序可以使用它来获取正确的结果
 * 
 *      #include <iostream>
 *      using namespace std;
 *      #include "complex_usr.h"
 * 
 *      int main()
 *      {   
 *          complex a(3.0, 4.0);
 *          complex c;
 *          cout << "Enter a complex number (q to quit):\n";
 *          while(cin >> c)
 *          {
 *              cout << "c is " << c << '\n';
 *              cout << "complex conjugate is " << ~c << '\n';
 *              cout << "a is " << a << '\n'
 *              cout << "a + c is " << a + c << '\n';
 *              cout << "a - c is " << a - c << '\n';
 *              cout << "a * c is " << a * c << '\n';
 *              cout << "2 * c is " << 2 * c << '\n';
 *              cout << "Enter a complex number (q to quit):\n";
 *          }
 *          cout << "Done!\n";
 *          return 0;
 *      }
 * 
 * 
 *  数据类型：
 *      实部和虚部——double
 *  行为：
 *      1,初始化构造函数
 *      2，默认构造函数
 *      3，重载<<运算符
 *      4，重载>>运算符
 *      5，重载+、-、*、~，其中*有两种重载
 */
#include <iostream>
#include <string>
class Complex
{
private:
    double real;
    double dummy;
public:
    //explicit Complex(double r = 0.0, double d = 0.0);
    Complex();
    Complex(double r, double d);
    //Complex(const Complex& i);
    Complex(Complex& i);
    ~Complex();
    Complex& operator=(Complex& i);

    //  action
    Complex operator+(Complex& i);
    Complex operator-(Complex& i);
    Complex operator*(Complex& i);
    Complex operator*(int i); 
    Complex operator~();
    std::string test();

    //  friend action
    friend std::ostream& operator<<(std::ostream& os, const Complex& m);
    friend bool operator>>(std::istream& is, Complex& m);
    friend Complex operator*(int n, const Complex& m);
};

#endif  /* SHOW_EXERCISE7_H */