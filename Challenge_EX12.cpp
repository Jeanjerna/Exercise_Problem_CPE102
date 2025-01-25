#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
using namespace std;

//----------------------------Function Prototype----------------------------//

void matrix_change_element(double source_matrix[] , int row , int column , double number , int source_matrix_size);
double matrix_access(double source_matrix[] , int row , int column, int source_matrix_size);
void user_create_A_Matrix(double source_matrix[] , int source_matrix_size);
void show_matrix(double source_matrix[], int source_matrix_size);
void resize_SourceMatrix_to_NewMatrix(double source_matrix[] , int delete_row , int delete_column , int source_matrix_size , double new_matrix[]);
double DET_FUNCTION(double source_matrix[] ,int source_matrix_size,int i);

//__________________________________________________________________________//

//------------MAIN-----------__________MAIN__________------------MAIN-----------//
int main()
{
    int Main_matrix_size , Main_matrix_sum_size;
    cout << "Please input matrix size : ";
    cin >> Main_matrix_size;
    Main_matrix_sum_size = Main_matrix_size * Main_matrix_size;

    double A[Main_matrix_sum_size]; 
    user_create_A_Matrix(A , Main_matrix_size); 

    //------------------------------TEST------------------------------//

    // Main_matrix_size = 3;
    // Main_matrix_sum_size = Main_matrix_size * Main_matrix_size;
    // double A[Main_matrix_sum_size] = {1,0,5,-1,4,7,1.2,0,4.5};

    // Main_matrix_size = 5;
    // Main_matrix_sum_size = Main_matrix_size * Main_matrix_size;
    // double A[Main_matrix_sum_size] = { 1.1 ,2.2 ,3.3 ,0 ,7.5 , 4 ,2 ,0 ,0 ,1 , 12 ,-6.9 ,4.3 ,0 ,2.1 , -1 ,-2 ,-3 ,-4 ,-5 , 7 ,7 ,7 ,6 ,9};

    // Main_matrix_size = 10;
    // Main_matrix_sum_size = Main_matrix_size * Main_matrix_size;
    // double A[Main_matrix_sum_size]={1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    //                                 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 
    //                                 1, 2, 3, 0, 0, 0, 0, 0, 0, 0, 
    //                                 0, 0, 0, 0.5, 0, 0, 0, 0, 0, 0, 
    //                                 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 
    //                                 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 
    //                                 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 
    //                                 0, 0, 0, 0, 0, 0, 0, 10, 0, 0, 
    //                                 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 
    //                                 0, 0, 0, 0, 0, 0, 0, -1, -1, -1};
    
    //------------------------------TEST------------------------------//

    show_matrix(A , Main_matrix_size);
    cout << "Determinant of your matrix is " << DET_FUNCTION(A , Main_matrix_size , 0);

}

//__________________________________________________________________________//


//-----------------------------------Function-----------------------------------//
//                                      |                                       //
//                                      |                                       //
//                                      V                                       //


void matrix_change_element(double source_matrix[] , int row , int column , double num , int source_matrix_size)
{
    int real_direction_in_array = source_matrix_size*row + column;
    source_matrix[real_direction_in_array] = num;
}

//============================================================================//
double matrix_access(double source_matrix[] , int row , int column , int source_matrix_size)
{
    int real_direction_in_array = source_matrix_size*row + column;
    return source_matrix[real_direction_in_array];
}

//============================================================================//

void user_create_A_Matrix(double source_matrix[] , int source_matrix_size)
{
    double num_input;
    for (int i = 0 ; i < source_matrix_size ; i++)
    {
        cout << "Input elements of row " << i+1 << " : ";
        for (int j = 0 ; j < source_matrix_size ; j++)
        {
            cin >> num_input;
            matrix_change_element(source_matrix , i , j , num_input , source_matrix_size);
        }
    }
}

//============================================================================//

void show_matrix(double source_matrix[] , int source_matrix_size)
{
    cout << "\n\n";
    for (int i = 0 ; i < source_matrix_size ; i++)
    {
        for (int j = 0 ; j < source_matrix_size ; j++)
        {
            cout << setw(5) << matrix_access(source_matrix , i , j , source_matrix_size);
        }
        cout << "\n";
    }

    cout << "\n\n";
}

//============================================================================//

void resize_SourceMatrix_to_NewMatrix(double source_matrix[] , int delete_row , int delete_column , int source_matrix_size , double new_matrix[])
{
    if (source_matrix_size <= 1) cout << "can't resize this matrix >> source_matrix_size = 1";
    else
    {
        int new_matrix_size;
        new_matrix_size = source_matrix_size - 1;
        for (int row = 0 ; row < source_matrix_size ; row++)
        {
            if (row == delete_row) continue;
            for (int column = 0 ; column < source_matrix_size ; column++)
            {
                if (column == delete_column) continue;
                matrix_change_element(new_matrix , (row < delete_row ? row : row-1) , (column < delete_column ? column : column-1) , matrix_access(source_matrix , row , column , source_matrix_size) , new_matrix_size);
            }
        }
    }
}

//============================================================================//

double DET_FUNCTION(double source_matrix[] ,int source_matrix_size ,int i)
{
    if (source_matrix_size == 1) return matrix_access(source_matrix , 0 , 0 , source_matrix_size);

    if (i > source_matrix_size - 1) return 0;

    int SubMatrix_Size = source_matrix_size - 1;
    double SubMatrix[SubMatrix_Size * SubMatrix_Size]; // แก้จาก SubMatrix[SubMatrix_Size] ไปเป็น SubMatrix[SubMatrix_Size * SubMatrix_Size] เฉยๆ

    resize_SourceMatrix_to_NewMatrix(source_matrix , 0 , i , source_matrix_size , SubMatrix);

    int pow_;
    if (i % 2 == 0) pow_ = 1;
    else pow_ = -1;
    return (matrix_access(source_matrix , 0 , i , source_matrix_size) * pow_ * DET_FUNCTION(SubMatrix , SubMatrix_Size , 0)) + (DET_FUNCTION(source_matrix , source_matrix_size , i+1));
}

//============================================================================//