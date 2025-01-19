#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

template <class Type>
void ShowInArray(const Type data[] , int size)
{
    cout << "\n-------------------\n\n";
    for (int i = 0 ; i < size ; i++)
    {
        cout << data[i] << endl;
    }
    cout << "\n-------------------\n\n";
}

template <class Type>
void sumInArray(const Type data[] , int size)
{
    long double sum = 0;
    for (int i = 0 ; i < size ; i++)
    {
        sum += data[i];
    }
    cout << "\n-------------------\n\n";
    cout << sum;
    cout << "\n-------------------\n\n";
}

int rand_Ex10(int N)
{
    long double possibility[N] = {1} , totalpossibility = 0;

    // สร้าง Array possibility ที่ค่าตัวแรกมีค่าเท่ากับ 1 และค่าถัดไปจะน้องลง ครึ่งหนึ่ง เช่น 1 , 0.5 , 0.25 , 0.125 ................
    for (int i = 1 ; i < N ; i++ )
    {
        possibility[i] = possibility[i-1]/2;
    }

    // ใช้เช็ค possibility ของแต่ละค่า 
    // ShowInArray(possibility , N);

    // หาผลรวมของค่า possibility
    for (int i = 0 ; i < N ; i++)
    {
        totalpossibility += possibility[i];
    }

    // แปลงค่า possibility ให้อยู่ในส่วน 1
    for (int i = 0 ; i < N ; i++)
    {
        possibility[i] = possibility[i] / totalpossibility * 1;
    }

    // ใช้เช็ค possibility ของแต่ละค่า 
    // ShowInArray(possibility , N);

    // ใช้เช็คผลรวมของ possibility 
    // sumInArray(possibility , N);

    long double num = double(rand()) / RAND_MAX * 1, randomnum; // RAND_MAX คือค่าสูงสุดที่จะ rand() ได้ โดยค่าที่สุมได้จะอยู่ในช่วง 0 - 1 แบบทศนิยม
    long double Upper_Possibility = 1 , Lower_Possibility ;

    // แสดงค่าที่สุ่มได้
    // cout << "num is " << num << endl;

    for (int i = 0 ; i < N ; i++)
    {
        Lower_Possibility = Upper_Possibility-possibility[i];

        if (num < Upper_Possibility and num > Lower_Possibility )
        {
            randomnum = i+1;
            break;
        }

        Upper_Possibility = Upper_Possibility-possibility[i];
    }
    
    return randomnum;
}

int main()
{
    srand(time(0));

    int N;
    cout << "Enter your number : ";
    cin >> N;

    double count[N] = {};
    double round = 1000000;

    for (int i = 0 ; i < round ; i++)
    {
        count[rand_Ex10(N) - 1]++;
    }

    for (int i = 0 ; i < N ; i++)
    {
        cout << "Number of " << i+1 << " is : " << count[i] << " / Precent is " << count[i]/round * 100 << " %" << endl; 
    }
}

