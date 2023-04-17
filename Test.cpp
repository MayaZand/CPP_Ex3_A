#include <iostream>
#include <stdexcept>
#include "doctest.h"
#include "sources/Fraction.hpp"
#include "sources/Fraction.cpp"


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

    CHECK (a+b==1);
    CHECK (a-b==0);
    CHECK (a*b==Fraction(1,4));
    CHECK (a*b == 0.25);
    CHECK (a/b==1);
    CHECK (b+a==1);
    CHECK (b-a==0);
    CHECK (b*a==Fraction(1,4));
    CHECK (b*a == 0.25);
    CHECK (b/a==1);
}

TEST_CASE("arithmetic test - between Fraction and a float num") //// just num
{
    Fraction a(1,2);

    CHECK (a+1==Fraction(3,2));
    CHECK (a-1==Fraction(-1,2));
    CHECK (a*2==Fraction(1,0));
    CHECK (a/1==Fraction(1,2));

    CHECK (a+1==1.5);
    CHECK (a-1==-0.5);
    CHECK (a*2==1);
    CHECK (a/1==0.5);

    CHECK (1+a==Fraction(3,2));
    CHECK (1-a==Fraction(1,2));
    CHECK (2*a==Fraction(1,0));
    CHECK (1/a==Fraction(1,2));

    CHECK (1+a==1.5);
    CHECK (1-a==0.5);
    CHECK (2*a==1);
    CHECK (1/a==2);
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
}