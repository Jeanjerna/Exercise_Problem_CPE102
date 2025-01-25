#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

double matrix_access(const double matrix[] , int N , int x , int y)
{   
    int locate;
    locate = N*x + y;
    return matrix[locate];
}

void new_matrix(double matrix[] , int N , int x , int y)
{
    double new_matrix[N-1][N-1];

    int i2 = 0 , y2 = 0 ;

    for (int i = 0 ; i < N ; i++)
    {
        if (i == x) continue;
        for (int j = 0 ; j < N ; j++)
        {
            if (j == y) continue;
            new_matrix[i2][y2] = matrix_access(matrix , N , i , j);
            y2++;
        }
        i2++;
    }

    int count = 0;

    for (int i = 0 ; i < N*N ; i++)
    {
        matrix[i] = 0;
    }

    for (int i = 0 ; i < N-1 ; i++)
    {
        for (int j = 0 ; j < N-1 ; j++)
        {
            matrix[count] = new_matrix[i][j];
            count++;
        }
    }
    
}

double det(const double matrix[] , int N)
{
    if (N == 1) return matrix_access(matrix , N , 0 , 0);
    else if (N == 0) return 0;
    else
    {
        // return matrix_access(matrix , N-1 , 0 , N-1) * pow(-1 , N-1) * det(matrix , N-1) + det(matrix , N-2);
    }
}

int main()
{
    int N , count = 0;
    cout << "Please input matrix size : ";
    cin >> N;

    double matrix[N*N] ;

    for (int i = 0 ; i < N ; i++ )
    {
        cout << "Input elements of row " << i+1 << " : " ;
        for (int j = 0 ; j < N ; j++)
        {
            cin >> matrix[count];
            count++;
        }
        cin.ignore();
    }

    

    //--------------------------------------------// // แสดงค่าใน matrix //
    cout << "\n-------------------\n\n";
    for (int i = 0 ; i < N ; i++)
    {
        for (int j = 0 ; j < N ; j++)
        {
            cout << matrix_access(matrix , N , i , j) << " ";
        }
        cout << "\n";
    }
    cout << "\n-------------------\n\n";
    // //--------------------------------------------// // แสดงค่าใน matrix //

    new_matrix(matrix , N , 0 , 3);

    //--------------------------------------------// // แสดงค่าใน matrix //
    cout << "\n-------------------\n\n";
    for (int i = 0 ; i < N ; i++)
    {
        for (int j = 0 ; j < N ; j++)
        {
            cout << matrix_access(matrix , N , i , j) << " ";
        }
        cout << "\n";
    }
    cout << "\n-------------------\n\n";
    // //--------------------------------------------// // แสดงค่าใน matrix //

    // cout << "Determinate of your matrix is " << det(matrix , N);
}