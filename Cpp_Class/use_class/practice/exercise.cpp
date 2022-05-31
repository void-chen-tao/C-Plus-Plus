#include "exercise.h"

#ifdef SHOW_EXERCISE7_H

Complex::Complex()
{
    real = 0.0;
    dummy = 0.0;
}

Complex::Complex(double r, double d)
{
    real = r;
    dummy = d;
}

/*  puzzle: Complex a.Complex(a)?  */
Complex::Complex(Complex &i)
{
    real = i.real;
    dummy = i.dummy;
}

Complex::~Complex()
{
}

Complex &Complex::operator=(Complex &i)
{
    if (this == &i)
        return *this;

    real = i.real;
    dummy = i.dummy;
    return *this;
}

Complex Complex::operator+(Complex &i)
{
    Complex temp(real + i.real, dummy + i.dummy);
    return temp;
}

Complex Complex::operator-(Complex &i)
{
    Complex temp(real - i.real, dummy - i.dummy);
    return temp;
}

Complex Complex::operator*(Complex &i)
{
    Complex temp(real * i.real - dummy * i.dummy, dummy * i.real + real * i.dummy);
    return temp;
}

Complex Complex::operator*(int i)
{
    Complex temp(i * real, i * dummy);
    return temp;
}

Complex Complex::operator~()
{
    Complex temp(real, -dummy);
    return temp;
}

std::ostream &operator<<(std::ostream &os, const Complex &m)
{
    os << "(" << m.real << ", " << m.dummy << "i)\n";
    return os;
}

bool operator>>(std::istream &is, Complex &m)
{
    double temp_r;
    double temp_v;

    std::cout << "Please Enter your real part\n";
    if ((is >> temp_r).good())
    {
        if (temp_r == 'Q' || temp_r == 'q')
        {
            std::cout << "Quit";
            return false;
        }

        std::cout << "Now, Please Enter your virtual part\n";
        if ((is >> temp_v).good())
        {
            if (temp_v == 'Q' || temp_v == 'q')
            {
                std::cout << "Quit\n";
                return false;
            }

            std::cout << "Your Complex is (" << temp_r << ", " << temp_v << "i)\n";
            m.real = temp_r;
            m.dummy = temp_v;
            return true;
        }
    }
    return false;
}

Complex operator*(int n, const Complex &m)
{
    Complex temp(n * m.real, n * m.dummy);
    return temp;
}

#endif /* SHOW_EXERCISE7_H */