#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

// ข้อที่ 3.1 //
double _2N(double N)
{
    if (N == 1) return 2;
    else return pow(2 , N) + _2N(N-1);
}
// ------------------------------------------ //

// ข้อที่ 3.2 //
double SQRT_N(double N)
{
    if (N == 1) return sqrt(1);
    else return sqrt(N * SQRT_N(N-1));
}
// ------------------------------------------ //

// ข้อที่ 3.3 //
double _1plusN(double N)
{
    if (N == 0) return 1;
    else return 1 + (N/(_1plusN(N-1)));
}
// ------------------------------------------ //

int main()
{
    cout << "\n\n--------------------------------------\n\n";

    cout << _2N(5); // Correct //

    cout << "\n\n--------------------------------------\n\n";

    cout << SQRT_N(5); // Correct //

    cout << "\n\n--------------------------------------\n\n";

    cout << _1plusN(5); // Correct //

    cout << "\n\n--------------------------------------\n\n";
}