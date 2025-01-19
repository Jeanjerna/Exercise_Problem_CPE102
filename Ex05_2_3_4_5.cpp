#include <iostream>
using namespace std;

void _234()
{
    int A[6] = {9 , -7 , 3 , 4 , -2 , 4};

    for (int i = 0 ; i < 6 ; i++)
    {
        cout << A[i] << " " ;
    }

    cout << "\n";
    
    for (int i = 0 ; i < 6 ; i++)
    {
        if (A[i] > 0) cout << A[i] << " " ;
    }

    cout << "\n";
}



void _5()
{

    cout << "\n";
    int A[10];
    int i = 0;
    while(i < 10)
    {
        if (i%2 == 0) A[i] = i;
        else A[i] = -i;
        i++;
    }

    
    i = 0;
    while(i < 10)
    {
        cout << A[i] << " ";
        i++;
    }
}


int main()
{

    _234();
    _5();

    return 0;
}