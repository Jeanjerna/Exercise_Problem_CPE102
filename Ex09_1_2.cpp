#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
using namespace std;

void XO()
{
    int N;
    cout << "Please input board size: ";
    cin >> N;

    for (int i = 1 ; i <= N ; i++){
        for (int j = 1; j < N ; j++){
            cout << "   ";
            if (j < N) cout << "|";
        }
        cout << "\n";
        if (i < N){
            for (int j = 1 ; j <= N ; j++){
                cout << "---";
                if (j < N) cout << "+";
            }
            cout << "\n";
        }
    }
}

void readScore()
{
    ifstream source;
    source.open("C:\\CMU_STUDY\\COMPUTER_PROGRAMMING_CMU\\261102_COMPUTER_PROGRAMMING\\score.txt");
    
    double min , max , count = 0 , num;
    cout << "Enter Range [min , max] : ";
    cin >> min >> max;

    if (min > max) cout << "Invalid input. (max >= min)";
    else
    {
        string text;
        while (getline(source , text))
        {
            num = stod(text);
            if (num >= min and num <= max) count++;
        }

        cout << "The number of student who have score in this range = " << count << endl;
    }
    
    source.close();
}

int main()
{
    XO();
    readScore();
}