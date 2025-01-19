#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
using namespace std;

void grade(char a)
{
    switch (a)
    {
        case 'A':
            cout << "Awesome" << endl; break;
        case 'B':
            cout << "Great" << endl; break;
        case 'C':
            cout << "Good" << endl; break;
        case 'F':
            cout << "Noob" << endl; break;
        default :
            cout << "Error: Invalid Input" << endl;
    }
}

string tommy(int x , int y)
{
    if (x < 50)
    {
        if (y < 50) return "Unfriend";
        else return "Friend";
    }
    else if (x >= 50 and x < 80)
    {
        if (y < 50) return "ONS";
        else return "Friend";
    }
    else
    {
        if (y < 50) return "ONS";
        else return "Girlfriend";
    }
}

void start()
{
    double x , y , z;
    cout << "PLS input x and y >> ";
    cin >> x >> y;

    if (x >= 20 and y >= 20 and x+y >= 50)
    {
        if (y > x) y = 2*y;

        z = (x+y)/2;
    }
    else
    {
        z = sqrt(pow(x,2) + pow(y,2));

        if (z > 50) z = 50;
    }

    cout << z;
}


int main()
{
    grade('A');
    grade('B');
    grade('C');
    grade('F');
    grade('X');

    cout << tommy(30 , 30) << endl;
    cout << tommy(30 , 70) << endl;
    cout << tommy(60 , 30) << endl;
    cout << tommy(60 , 70) << endl;
    cout << tommy(90 , 30) << endl;
    cout << tommy(90 , 70) << endl;

    start();
}