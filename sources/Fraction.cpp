#include "Fraction.hpp"

using namespace ariel;

Fraction::Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {};

Fraction Fraction::operator+(const Fraction& other)
{
    int num = numerator * other.denominator + other.numerator * denominator;
    int denom = denominator * other.denominator;
    int gcd = std::gcd(num, denom); // greatest common divisor - reduces the resulting fraction to its lowest terms
    return Fraction(num / gcd, denom / gcd);
}

Fraction Fraction:: operator-(const Fraction& other) 
{
    int num = numerator * other.denominator - other.numerator * denominator;
    int denom = denominator * other.denominator;
    int gcd = std::gcd(num, denom); // greatest common divisor - reduces the resulting fraction to its lowest terms
    return Fraction(num / gcd, denom / gcd);
}

Fraction Fraction:: operator*(const Fraction& other)
{
    int num = numerator * other.numerator;
    int denom = denominator * other.denominator;
    int gcd = std::gcd(num, denom); // greatest common divisor - reduces the resulting fraction to its lowest terms
    return Fraction(num / gcd, denom / gcd);
}

Fraction Fraction:: operator/(const Fraction& other) 
{
    int num = numerator * other.denominator;
    int denom = denominator * other.numerator;
    int gcd = std::gcd(num, denom); // greatest common divisor - reduces the resulting fraction to its lowest terms
    return Fraction(num / gcd, denom / gcd);
}

bool Fraction:: operator==(const Fraction& other)
{
    return numerator * other.denominator == other.numerator * denominator;
}

bool Fraction:: operator<(const Fraction& other)  
{
    return numerator * other.denominator < other.numerator * denominator;
}

bool Fraction:: operator>(const Fraction& other)  
{
    return numerator * other.denominator > other.numerator * denominator;
}

bool Fraction:: operator<=(const Fraction& other)  
{
    return numerator * other.denominator <= other.numerator * denominator;
}

bool Fraction:: operator>=(const Fraction& other)  
{
    return numerator * other.denominator >= other.numerator * denominator;
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
    numerator += denominator;
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
    numerator -= denominator;
    simplify();
    return *this;
}

Fraction Fraction:: operator--(int) 
{
    Fraction temp(*this);
    --(*this);
    return temp;
}

ostream& Fraction:: operator<<(ostream& os) 
{
   // os << numerator << '/' << denominator;
    return os;
}

istream& Fraction:: operator>>(std::istream& is) 
{
   // is >> numerator >> '/' >> denominator;
    return is;
}
