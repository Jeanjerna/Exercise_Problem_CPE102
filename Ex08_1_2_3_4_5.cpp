#include <cmath>
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

void _1()
{
    double sum = 0;

    for (double i = 2 ; i <= 222 ; i = i + 2)
    {
        sum += 1/i;
    }

    cout << fixed << setprecision(10);
    cout << sum << endl;
    cout << defaultfloat << setprecision(6);
    cout << sum << endl;
}

void _2()
{
    double sum = 0;

    int i = 3, j = 1;

    for (; i <= 333 ; i = i + 3 , j++)
    {
        if (j%2 == 0) sum += pow(i,2);
        else sum += pow(i,3);
    }

    cout << sum << endl;
}

void _3()
{
    int a , min;
    cout << "Input number: ";
    cin >> a;

    min = a;

    if (min <= 0) cout << "Minimun = N/A" << endl;
    else
    {
        while (true)
        {
            cout << "Input number: ";
            cin >> a;

            if (a <= 0) break;

            if (a < min) min = a;
        }

        cout << "Minimun = " << min << endl;
    }
}

void prinyPattern1(int N , int M)
{
    if (N <=0 or M <= 0) cout << "NOOOOOOO";
    else
    {
        for (int i = 0 ; i < N ; i++)
        {
            for (int j = 0 ; j < M ; j++)
            {
                if (i%2 == 0)
                {
                    if (j%2 == 0) cout << "O";
                    else cout << "X";
                }
                else 
                {
                    if (j%2 == 0) cout << "X";
                    else cout << "O";
                }
            }

            cout << "\n";
        }
    }

    cout << "\n";
}

void prinyPattern2(int N)
{
    if (N <= 0) cout << "NOOOOO";
    else
    {
        for (int i = 1 ; i <= N ; i++)
        {
            for (int j = 1 ; j <= N ; j++)
            {
                if (j <= i) cout << "O";
                else cout << "X"; 
            }
            cout << "\n";
        }
    }

    cout << "\n";
}

int main()
{
    _1();
    cout << "\n/////////////////////////////////////\n";
    _2();
    cout << "\n/////////////////////////////////////\n";
    _3();
    cout << "\n/////////////////////////////////////\n";
    prinyPattern1(2,2);
    prinyPattern1(3,5);
    prinyPattern1(5,3);
    prinyPattern1(0,3);
    prinyPattern1(7,-1);
    cout << "\n/////////////////////////////////////\n";
    prinyPattern2(3);
    prinyPattern2(4);
    prinyPattern2(5);
    prinyPattern2(0);
    prinyPattern2(-1);
}