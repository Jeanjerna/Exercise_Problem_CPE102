#include <iostream>
using namespace std;

template <typename Type>
void insert(const Type [], Type [], int, Type, int);

int main()
{
    int N = 4;
    int x[N] = {1,4,9,7}, y[N+1],z[N+1];

    insert(x,y,N,69,2); //insert value 69 at index 2
    insert(x,z,N,77,0); //insert value 77 at index 0

    cout << "x = ";

    for(int i = 0; i < N;i++) cout << x[i] << " ";

    cout << "\ny = ";

    for(int i = 0; i < N+1;i++) cout << y[i] << " ";
    
    cout << "\nz = ";

    for(int i = 0; i < N+1;i++) cout << z[i] << " ";

    return 0;
}
//write function insert() here

template <class Type>
void insert(const Type x[], Type y[], int N, Type data, int dir)
{
    int i;
    for (i = 0 ; i < dir ; i++)
    {
        y[i] = x[i];
    }

    y[dir] = data;

    for (int j = dir+1 ; j < N+1 ; j++)
    {
        y[j] = x[i]; //ที่ตรงนี้ใช้เป็น i เฉยๆ เพราะจาก for ครั้งก่อนจะมีการบวก i ไปอีก 1 ก่อนจะจบ loop ทำให้ล่าสุด i มีค่าเท่ากับ dir
        i++;
    }

    /*
    for (int j = dir+1 ; j < N+1 ; j++)
    {
        y[j] = x[j-1]; // แบบที่ 2 //
    }
    */
}