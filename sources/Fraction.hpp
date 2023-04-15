/* During the preperation of this assignment I used the internet and chat GPT */

#include <iostream>
#include <numeric> 

using namespace std;
namespace ariel
{
   class Fraction
   {

    /*fields - private by default: */
    int numerator;
    int denominator;

    /*constructor, copy constructor and destructor: */
    public:
    Fraction(int numerator, int denominator);

    /*methods: */

    /*
    this method add two fractions and return their sum as another fraction in reduced form.
    */
    Fraction operator+(const Fraction& other);

    /*
    this method subtract two fractions and return their difference as another fraction in reduced form.
    */
    Fraction operator-(const Fraction& other);

    /*
    this method multiply two fractions and return their product as another fraction in reduced form.
    */
    Fraction operator*(const Fraction& other);

    /*
    this method divide two fractions and return their quotient as another fraction in reduced form.
    */
    Fraction operator/(const Fraction& other);

    /*
    this method compare two fractions for equality and return true or false.
    */
    bool operator==(const Fraction& other);

    /*
    this method compare two products and return true if the first product is less than the second, and false otherwise.
    */
    bool operator<(const Fraction& other);

    /*
    this method compare two products and return true if the second product is less than the first, and false otherwise.
    */
    bool operator>(const Fraction& other);

    /*
    this method compare two products and return true if the first product is less or equal to the second, and false otherwise.
    */
    bool operator<=(const Fraction& other);

    /*
    this method compare two products and return true if the second product is less or equal to the first, and false otherwise.
    */
    bool operator>=(const Fraction& other);

    /*
    this method reduce fraction to its simplest form.
    */
    void simplify();

    /*
    this method adds 1 to the fraction - prefix implementation
    */
    Fraction& operator++();
        
    /*
    this method adds 1 to the fraction - postfix implementation
    */
    Fraction operator++(int);

    /*
    this method substracts 1 from the fraction - prefix implementation
    */
   Fraction& operator--();

    /*
    this method substracts 1 from the fraction - postfix implementation
    */
    Fraction operator--(int);

    /*
    this method prints a fraction to an output stream in the format “numerator/denominator”.
    @param os is the output stream
    */
    ostream& operator<<(ostream& os);

    /*
    this method reads a fraction from an input stream by taking two integers as input.
    @param is is the input stream
    */
    istream& operator>>(std::istream& is);

   } 

}

