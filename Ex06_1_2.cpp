#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
using namespace std;

int X_Y_count(string x)
{
    int len = x.size()  , xcount = 0 , ycount = 0;

    for (int i = 0 ; i < len ; i++)
    {
        if (x[i] == 'X') xcount++;
        else ycount++;
    }

    if (xcount > ycount) return 1;
    else if (ycount > xcount) return -1;
    else return 0;
}

void X_Y_count_test()
{
    cout << X_Y_count("XYXXYX") << endl;
    cout << X_Y_count("XXYY") << endl;
    cout << X_Y_count("XYYYYY") << endl;
    cout << X_Y_count("XYXY") << endl;
    cout << X_Y_count("XXXXXYYYY") << endl;
    cout << X_Y_count("Y") << endl << endl;
}

////////////////////////////////////////////////

char check_aeiou(char a)
{
    char e[] = {'A' , 'E' , 'I' , 'O' , 'U' , 'a' , 'e' , 'i' , 'o' , 'u'};
    char e2[] = "AEIOUaeiou";
    string e3 = "AEIOUaeiou";

    // ใช้ e ชุดข้อมูล a e i o u แบบไหนก็ได้ตามตัวอย่างข้างต้น e e2 e3 //

    int i = 0;
    for ( ; i < 10 ; i++)
    {
        if (a == e[i]) return 'y';
    }
    return 'n';
}

void check_aeiou_test()
{
    cout << check_aeiou('A') << endl;
    cout << check_aeiou('a') << endl;
    cout << check_aeiou('B') << endl;
    cout << check_aeiou('z') << endl;
    cout << check_aeiou('6') << endl;
    cout << check_aeiou('U') << endl;
    cout << check_aeiou('i') << endl << endl;
}

////////////////////////////////////////////////



int main()
{
    X_Y_count_test();
    check_aeiou_test();
}