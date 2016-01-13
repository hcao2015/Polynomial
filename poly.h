/***************************************************
 * poly.h interface for a linked list implementation of a
 * polynomial ADT. 
 ***************************************************/ 
#include <iostream>
#ifndef POLY_H
#define POLY_H

class poly
{
    private:
        double *coef;
        int deg;
    public:
        poly(); //constructor
        ~poly(); //destructor
        poly(const poly & P); //copy constructor

        //overload assignment
        poly & operator = (const poly & P);

        // overload input and output
        friend ostream & operator << (ostream &, const poly &);
        friend istream & operator >> (istream &, poly &);

        //overload operations
        friend poly operator * (const poly &P1, const poly &P2);
        friend poly operator + (const poly &P1, const poly &P2);
        friend poly operator - (const poly &P1, const poly &P2);

        //overload comparation
        friend bool operator <(const poly & P1, const poly & P2);

        //subs x
        double multx(double);

        //derivative and antiderivative
        poly Derivative();
        poly AntiDerivative();

        //make absolute
        poly makeAbsolute();
        //multi scalar
        void multiScalar(double Scalar);

};
        
#include "poly.cpp"
#endif