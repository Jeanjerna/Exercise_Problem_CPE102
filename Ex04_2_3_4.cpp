#include <cmath>
#include <iostream>
using namespace std;

int greatDivisor(int a)
{
    /* /////////////////////////////////////////////////// <<
    if (a == 1) return 1;
    else
    {
        int i = a;

        // for ( ; not((i < a) and ((a%i) == 0)) ; i--) {}
        // return i;

        while (i >= 1)
        {
            if ((i < a) and ((a%i) == 0)) return i;
            else i--;
        }
    }
    *//////////////////////////////////////////////////// <<

    int i = a;

    if (a == 1) return 1;
    else
    {
        while (true)
        {
            i = i-1;
            if (a%i == 0)
            {
                return i;
                break;
            }
        }
    }
}


double findKineticEnergy(double m , double v)
{
    return (0.5 * m * (pow(v,2)));
}


double y(double x)
{
    double _sin , _ln ;
    _sin = ( pow(x,3) ); 
    _ln = ((2*x + 1) / (pow(x,2))); 

    return sin(_sin) / log(_ln);
}

int main(){
    cout << greatDivisor(1) << endl;
    cout << greatDivisor(12) << endl;
    cout << greatDivisor(91) << endl;
    cout << greatDivisor(49) << endl;
    cout << greatDivisor(81) << endl;
    cout << greatDivisor(55) << endl << endl;

    cout << findKineticEnergy(5 , 2) << endl << endl;

    cout << y(5) << endl;
}