#include "poly.h"
/**************************************************/
// constructor
poly::poly() {
    this -> coef = new double[1011];
    this -> deg = 0;
    memset(this->coef, 0, sizeof(this->coef));
}
/**************************************************/
// destructor
poly::~poly() {
    delete this -> coef;
}
/**************************************************/
// deep contructor
poly::poly(const poly &P) {
    this -> deg = P.deg;
    this -> coef = new double [1011];
    memset(this -> coef, 0, sizeof(this -> coef));
    for(int i = 0; i <= deg; i ++)
        this -> coef[i] = P.coef[i];
}
/**************************************************/
// operator = 
poly & poly::operator = (const poly & P) {
    this -> deg = P.deg;
    for(int i = 0; i <= deg; i ++)
        this -> coef[i] = P.coef[i];
}
/**************************************************/
// operator < 
bool operator < (const poly & P1, const poly & P2) {
    if (P1.deg < P2.deg) return true;
    return false;
}
/**************************************************/
// overload operator *
poly operator * (const poly &P1, const poly &P2) {
    poly Res;
    Res.deg = P1.deg + P2.deg;
    for(int i = 0; i <= P1.deg; i ++)
        for(int j = 0; j <= P2.deg; j ++) {
            Res.coef[i + j] += P1.coef[i] * P2.coef[j];
        }
    return Res;
}
/**************************************************/
// overload operator +
poly operator + (const poly &P1, const poly &P2){
    poly Res;
    Res.deg = max(P1.deg, P2.deg);
    for(int i = 0; i <= max(P1.deg, P2.deg); i ++)
        Res.coef[i] = P1.coef[i] + P2.coef[i];
    return Res;
}
/**************************************************/
// overload operator -
poly operator - (const poly &P1, const poly &P2){
    poly Res;
    Res.deg = max(P1.deg, P2.deg);
    for(int i = 0; i <= max(P1.deg, P2.deg); i ++)
        Res.coef[i] = P1.coef[i] - P2.coef[i];
    return Res;
}
/**************************************************/
// The value of polynomial at x
double poly::multx(double x)
{
    double result = coef[deg];
    for (int i = deg-1; i >=0; i--)
        result = result*x + coef[i];
    return result;
}
/**************************************************
overload the output of the polynomial
 **************************************************/
ostream & operator << (ostream &os, const poly &P) {
    for(int i = 0; i < P.deg; i ++) {
        if (abs(P.coef[i]) > 1e-5) 
		os << P.coef[i] << "*" << "x^" << i << " + ";
    }
    os << P.coef[P.deg] << "*" << "x^" << P.deg;
    return os;
}
/**************************************************
Overload input the polynomials
 **************************************************/
istream & operator >> (istream &is, poly &P) {
    while (true) {
        try {
            cout << "Input the degree of polynomial: ";
            is >> P.deg;
            if (P.deg < 0) throw 1;
            else throw 0.1;
        }
        catch (int e) {
            cout << "Degree must not be negative." << endl;
        }
        catch(double e) {
            break;
        }
    }
    cout << "Input the coefficients seperately by space from degree 0 to "
	 		  << P.deg << ": \n";
    for(int i = 0; i <= P.deg; i ++)
    	{
         is >> P.coef[i];
    	}
    return is;
}
/***************************************************
 Derivative function
 Reduce degree and multiply it into the coefficient
 **************************************************/
poly poly::Derivative() {
    poly Res;
    if (this -> deg == 0) return Res;
    Res.deg = this -> deg - 1;
    for(int i = 0; i <= Res.deg; i ++)
        Res.coef[i] = this->coef[i + 1] * (i + 1);
    return Res;
}
/**************************************************
Antiderivative function
increase degree and  divide the coef to the deg
 **************************************************/
poly poly::AntiDerivative() {
    poly Res;
    Res.deg = this -> deg + 1;
    for(int i = 1; i <= Res.deg; i ++)
        Res.coef[i] = this -> coef[i - 1] / (1.0 * i);
    return Res;
}
/**************************************************
Return the absolute value of the polynomial
 **************************************************/
poly poly::makeAbsolute() {
    poly Res;
    Res.deg = this->deg;
    for(int i = 0; i <= Res.deg; i ++)
        Res.coef[i] = abs(this -> coef[i]);
    return Res;
}
/**************************************************
Multiply the poly with a scalar x
 **************************************************/
void poly::multiScalar(double Scalar) {
    for(int i = 0; i <= this -> deg; i ++)
        this -> coef[i] *= Scalar;
}
/**************************************************
subfunction for the multiScalar above
 **************************************************/
void multiX(poly & P) {
    cout << "Input the value for x: " << endl;
    double x;
    cin >> x;
    P.multiScalar(x);
    cout << "new P: " << P << endl;
}
void reduce(poly &P) {
    cout << "The polynomial is already in reduced form " << endl;
}