#include <iostream>
#include <stdexcept>
#include "doctest.h"
#include "sources/Fraction.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("denominator is zero")
{
    CHECK_THROWS(Fraction(1, 0));
}

TEST_CASE("division by zero")
{   
    Fraction a(1,2), b(0,3);

    CHECK_THROWS (a/b);
    CHECK_THROWS (a/0);
    CHECK_THROWS (b/0);
    CHECK_THROWS (2/b);
}

TEST_CASE ("arithmetic test - between two Fractions")
{
    Fraction a(1,2), b(3,6);

    // a is on the left side of the operator
    CHECK (a+b==1);
    CHECK (a-b==0);
    CHECK (a*b==Fraction(1,4));
    CHECK (a*b == 0.25);
    CHECK (a/b==1);
    
    // b is on the left side of the operator
    CHECK (b+a==1);
    CHECK (b-a==0);
    CHECK (b*a==Fraction(1,4));
    CHECK (b*a == 0.25);
    CHECK (b/a==1);
}

TEST_CASE("arithmetic test - between Fraction and number") 
{
    Fraction a(1,2), b(1,1);

    // a is on the left side of the operator - with int number
    CHECK (a+1==Fraction(3,2));
    CHECK (a-1==Fraction(-1,2));
    CHECK (a*2==Fraction(1,0));
    CHECK (a/1==Fraction(1,2));
    CHECK (a+1==1.5);
    CHECK (a-1==-0.5);
    CHECK (a*2==1);
    CHECK (a/1==0.5);
    
    // b is on the left side of the operator - with float number
    CHECK (b+2.421==3.421);
    CHECK (b-2.421==-1.421);
    CHECK (b*2.421==2.421);
    CHECK (b/2.421==Fraction(1000,2421)); 
    CHECK (b+2.421==Fraction(3.421));
    CHECK (b-2.421==Fraction(-1421,1000));
    CHECK (b*2.421==Fraction(2421,1000));

    // a is on the right side of the operator - with int
    CHECK (1+a==Fraction(3,2));
    CHECK (1-a==Fraction(1,2));
    CHECK (2*a==Fraction(1,0));
    CHECK (1/a==Fraction(1,2));
    CHECK (1+a==1.5);
    CHECK (1-a==0.5);
    CHECK (2*a==1);
    CHECK (1/a==2);

    // b is on the right side of the operator - with float
    CHECK (2.421+b==Fraction(3421,1000));
    CHECK (2.421-b==Fraction(1421,1000));
    CHECK (2.421*b==Fraction(2421,1000));
    CHECK (2.421/b==Fraction(2421,1000));
    CHECK (2.421+b==3.421);
    CHECK (2.421-b==1.421);
    CHECK (2.421*b==2.421);
    CHECK (2.421/b==2.421);
}

TEST_CASE("commutativity")
{
    Fraction a(1,2), b(3,6);

    CHECK ((a*b) == (b*a));
    CHECK ((a+b) == (b+a));
}

TEST_CASE("associative in multiplication")
{
    Fraction a(1,2), b(3,6), c(4,5);

    CHECK ( (a*(b*c)) == ((a*b)*c) );
    CHECK ( (a*(b*c)) == (a*b*c) );
    CHECK ( ((a*b)*c) == (a*b*c) );
}

TEST_CASE ("distibutive in multiplication")
{
    Fraction a(1,2), b(3,6), c(4,5);

    CHECK (a*(b+c) == (a*b + a*c));
    CHECK ((a+b)*c == (a*c + b*c));
}

TEST_CASE("Equality check")
{
    Fraction a(1,2), b(3,6);

    CHECK (a==0.5);
    CHECK (b==0.5);
    CHECK (b==a);
    CHECK (a==b);
    CHECK (a-b == 0);
    CHECK (a*b == 0.25);
    CHECK (a/b == 1);
    CHECK (b-a == 0);
    CHECK (b*a == 0.25);
    CHECK (b/a == 1);
    CHECK (Fraction(2412,1000) == 2.412);
}

TEST_CASE("check the <=, <, >=, > operators")
{
    Fraction a(1,2), b(3,6), c(0,1);
    
    // right side & left side of the operator, with two fractions, int and float
    CHECK ((a<=b) == true);
    CHECK ((b<=a) == true);
    CHECK ((a>=b) == true);
    CHECK ((b>=a) == true);
    CHECK ((c<=b) == true);
    CHECK ((c<=a) == true);
    CHECK ((a>=c) == true);
    CHECK ((b>=c) == true);
    CHECK ((c<b) == true);
    CHECK ((c<a) == true);
    CHECK ((a>c) == true);
    CHECK ((b>c) == true);
    CHECK ((a<3.5) == true);
    CHECK ((a<=3.5) == true);
    CHECK ((a>0) == true);
    CHECK ((a>=0) == true);
    CHECK ((3.5>a) == true);
    CHECK ((3.5>=a) == true);
    CHECK ((0<a) == true);
    CHECK ((0<=a) == true);

    // check if returns false
    CHECK ((a>=b) == false);
    CHECK ((b>=a) == false);
    CHECK ((a<=b) == false);
    CHECK ((b<=a) == false);
    CHECK ((c>=b) == false);
    CHECK ((c>=a) == false);
    CHECK ((a<=c) == false);
    CHECK ((b<=c) == false);
    CHECK ((c>b) == false);
    CHECK ((c>a) == false);
    CHECK ((a<c) == false);
    CHECK ((b<c) == false);
}

TEST_CASE("check the ++ and -- operators")
{
   Fraction a(1,2), b(3,6), c(0,1); 

   CHECK ((a++) == 1.5);
   CHECK ((a++) == Fraction(3,2));
   CHECK ((++a) == 1.5);
   CHECK ((++a) == Fraction(3,2));
   
   CHECK ((a--) == -1.5);
   CHECK ((a--) == Fraction(-3,2));
   CHECK ((--a) == -1.5);
   CHECK ((--a) == Fraction(-3,2));
}