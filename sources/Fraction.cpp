#include "Fraction.hpp"

using namespace ariel;

Fraction:: Fraction(): numerator(0), denominator(1){};
Fraction:: Fraction(int numerator, int denominator)
{   
    
    if (denominator == 0)
    {
        throw invalid_argument ("denominator can't be 0!");
    }
    this->denominator=denominator;
    this->numerator=numerator;
}

Fraction:: Fraction(float number) 
{
    int numerator = round(number * 1000);
    int denominator = 1000;
    int gcd_num = __gcd(numerator, denominator);
    numerator /= gcd_num;
    denominator /= gcd_num;
}


int Fraction:: getNumerator() const
{
    return this->numerator;
}

int Fraction:: getDenominator() const
{
    return this->denominator;
}

Fraction Fraction::operator+(const Fraction& other)
{
    int num = this->numerator * other.getDenominator() + other.getNumerator() * this->denominator;
    int denom = this->denominator * other.getDenominator();
    int gcd = std::gcd(num, denom); // greatest common divisor - reduces the resulting fraction to its lowest terms
    return Fraction(num / gcd, denom / gcd);
}

Fraction Fraction:: operator+(float num)
{
    return Fraction(2,2);
}

Fraction ariel:: operator+(float num, const Fraction& other)
{
    return Fraction(1,1);
}

Fraction Fraction:: operator-(const Fraction& other) 
{
    int num = this->numerator * other.getDenominator() - other.getNumerator() * this->denominator;
    int denom = this->denominator * other.getDenominator();
    int gcd = std::gcd(num, denom); // greatest common divisor - reduces the resulting fraction to its lowest terms
    return Fraction(num / gcd, denom / gcd);
}

Fraction Fraction:: operator-(float num)
{
    return Fraction(1,1);
}

Fraction ariel:: operator-(float num, const Fraction& other)
{
    return Fraction(1,1);
}


Fraction Fraction:: operator*(const Fraction& other)
{
    int num = this->numerator * other.getNumerator();
    int denom = this->denominator * other.getDenominator();
    int gcd = std::gcd(num, denom); // greatest common divisor - reduces the resulting fraction to its lowest terms
    return Fraction(num / gcd, denom / gcd);
}

Fraction Fraction:: operator*(float num)
{
    return Fraction(1,1);
}
Fraction ariel:: operator*(float num, const Fraction& other)
{
    return Fraction(1,1);
}

Fraction Fraction:: operator/(const Fraction& other) 
{
    int num = this->numerator * other.getDenominator();
    int denom = this->denominator * other.getNumerator();
    int gcd = std::gcd(num, denom); // greatest common divisor - reduces the resulting fraction to its lowest terms
    return Fraction(num / gcd, denom / gcd);
}

Fraction Fraction:: operator/(float num)
{
    return Fraction(1,1);
}

Fraction ariel:: operator/(float num, const Fraction& other)
{
    return Fraction(1,1);
}



bool Fraction:: operator==(const Fraction& other)
{
    return this->numerator * other.getDenominator() == other.getNumerator() * this->denominator;
}

bool Fraction:: operator==(float num)
{
    return false;
}

bool ariel:: operator==(float num, const Fraction& other)
{
    return false;
}
 

bool Fraction:: operator<(const Fraction& other)  
{
    return this->numerator * other.getDenominator() < other.getNumerator() * this->denominator;
}

bool Fraction:: operator<(float num)
{
    return false;
}

bool ariel:: operator<(float num, const Fraction& other)
{
    return false;
}





bool Fraction:: operator>(const Fraction& other)  
{
    return this->numerator * other.getDenominator() > other.getNumerator() * this->denominator;
}

bool Fraction:: operator>(float num)
{
    return false;
}

bool ariel:: operator>(float num, const Fraction& other)
{
    return false;
}




bool Fraction:: operator<=(const Fraction& other)  
{
   return this->numerator * other.getDenominator() <= other.getNumerator() * this->denominator;
}

bool Fraction::  operator<=(float num)
{
    return false;
}

bool ariel:: operator<=(float num, const Fraction& other)
{
    return false;
}



bool Fraction:: operator>=(float num)
{
    return false;
}

bool ariel:: operator>=(float num, const Fraction& other)
{
    return false;
}

bool Fraction:: operator>=(const Fraction& other)  
{
    return this->numerator * other.getDenominator() >= other.getNumerator() * this->denominator;
}



void Fraction:: simplify() 
{

    // Handle cases where numerator or denominator is zero or one.
    if (numerator == 0 || denominator == 1) 
    {
        return;
    }
    if (denominator == 0) 
    {
        throw invalid_argument("Invalid fraction: denominator cannot be zero.");
    }
    if (numerator == 1) 
    {
        return;
    }
    
    // Compute the greatest common divisor (gcd) of the numerator and denominator.
    int a = numerator;
    int b = denominator;
    int temp;
    while (b != 0) 
    {
        temp = b;
        b = a % b;
        a = temp;
    }
    int gcd = a;
    
    // Reduce the fraction by dividing both numerator and denominator by gcd.
    numerator /= gcd;
    denominator /= gcd;
    
    // Ensure that the denominator is positive.
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}

Fraction& Fraction:: operator++() 
{
    this->numerator += this->denominator;
    simplify();
    return *this;
}

Fraction Fraction:: operator++(int) 
{
    Fraction temp(*this);
    ++(*this);
    return temp;
}

Fraction& Fraction::  operator--() 
{
    this->numerator -= this->denominator;
    simplify();
    return *this;
}

Fraction Fraction:: operator--(int) 
{
    Fraction temp(*this);
    --(*this);
    return temp;
}

ostream& ariel:: operator<<(ostream& os, const Fraction& other)
{
    return (os << other.getNumerator() << '/' << other.getDenominator());
}

istream& ariel:: operator>>(istream& is, const Fraction& other) 
{
    return is;
}

