#include <iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>

using namespace std;

#include "poly.h"

int main()
{
 int c;
 poly P,Q, deP, antiDev;
 while (1)
 {
    cout <<"\nChoose your option below:\n\
            1. Enter your P(x) va Q(x)\n\
            2. Print P(x) va Q(x)\n\
            3. Value of P(x) at x\n\
            4. Derivative of P(x)\n\
            5. Antiderivative P(x)\n\
            6. Sum of P(x) va Q(x)\n\
            7. Difference P(x)-Q(x)\n\
            8. Product of P and Q\n\
            9. Absolute value of P \n\
            10. x*P(x) \n\
            11. Duplicate P(x) \n\
            12. Reduce P(x) \n\
            13. Exit"<<endl;
    cout << "Your option is : ";
    cin >>c;
    switch(c)
    {
        case 1:
            cout<<"Enter information of P(x):\n";
 		    cin >> P;
	        cout<<"Enter information of Q(x):\n";
		    cin >> Q;
		    break;
        case 2:
            cout<<"\n P(x) =  " << P;
	        cout<<"\n Q(x) =  " << Q;
		    break;
        case 3:
            cout<<"Input a constant x : ";
            double x;
 		    cin  >> x;
            cout<<"P("<<x<<") = "<< P.multx(x);
		    break;
        case 4:
            deP = P.Derivative();
            cout << "Derivative = " << deP << endl;
            break;
        case 5:
            antiDev = P.AntiDerivative();
            cout << "Anti-Derivative = " << antiDev << endl;
            break;
        case 6:
            cout << "Sum of P + Q = " << (P + Q) << endl;
		    break;
        case 7:
            cout << " Difference between P - Q = "<< (P - Q) <<endl;
 			break;
        case 8:
            cout << "Multiplication P*Q = " << (P * Q) << endl;
 			break;
        case 9:
            cout << P.makeAbsolute() << endl;
            break;
        case 10:
            multiX(P);
            break;
        case 11:
            //duplicate
            break;
        case 12:
            reduce(P);
            cout << P <<endl;
            break;
        case 13:
            return 0;
            break;
    }
  }
 return 0;
 }