#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
using namespace std;

//----------------Gobal variable-------------------//

// int Main_matrix_size , Main_matrix_sum_size ;

//_________________________________________________//


//----------------------------Function Prototype----------------------------//

void matrix_change_element(double source_matrix[] , int row , int column , double number , int source_matrix_size);
double matrix_access(double source_matrix[] , int row , int column, int source_matrix_size);
void user_create_A_Matrix(double source_matrix[] , int source_matrix_size);
void show_matrix(double source_matrix[], int source_matrix_size);
// int resize_SourceMatrix(double source_matrix[] , int delete_row , int delete_column, int source_matrix_size);
void resize_SourceMatrix_to_NewMatrix(double source_matrix[] , int delete_row , int delete_column , int source_matrix_size , double new_matrix[]);

double DET_FUNCTION(double source_matrix[] ,long int source_matrix_size,long int i);

//__________________________________________________________________________//


//------------MAIN-----------__________MAIN__________------------MAIN-----------//
int main()
{
    int Main_matrix_size , Main_matrix_sum_size;
    cout << "Please input matrix size : "; // +++ เอา comment ออกตอนจะใช้งานจริง
    cin >> Main_matrix_size; // +++ เอา comment ออกตอนจะใช้งานจริง
    Main_matrix_sum_size = Main_matrix_size * Main_matrix_size;

    double A[Main_matrix_sum_size]; // +++ เอา comment ออกตอนจะใช้งานจริง
    user_create_A_Matrix(A , Main_matrix_size); // +++ เอา comment ออกตอนจะใช้งานจริง

    show_matrix(A , Main_matrix_size);

    cout << "Determinant of your matrix is " << DET_FUNCTION(A , Main_matrix_size , 0);



    //------------------------------TEST------------------------------//

    // Main_matrix_size = 3;
    // Main_matrix_sum_size = Main_matrix_size * Main_matrix_size;
    // double A[Main_matrix_sum_size] = {1,0,5,-1,4,7,1.2,0,4.5};

    // Main_matrix_size = 4;
    // Main_matrix_sum_size = Main_matrix_size * Main_matrix_size;
    // double A[Main_matrix_sum_size] = {1,2,3,4,1,2,3,4,1,2,3,4,1,2,3,4};

    // Main_matrix_size = 10;
    // Main_matrix_sum_size = Main_matrix_size * Main_matrix_size;
    // double A[Main_matrix_sum_size] = {1,0,5,-1,4,7,1.2,0,4.5};

    // show_matrix(A , Main_matrix_size);

    // cout << "Determinant of your matrix is " << DET_FUNCTION(A , Main_matrix_size , 0);

    //------------------------------TEST------------------------------//

    
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

// int resize_SourceMatrix(double source_matrix[] , int delete_row , int delete_column , int source_matrix_size)
// {
//     if (source_matrix_size == 1) cout << "can't resize this matrix >> source_matrix_size = 1";
//     else
//     {
//         int new_matrix_size = source_matrix_size - 1;
//         for (int row = 0 ; row < source_matrix_size ; row++)
//         {
//             if (row == delete_row) continue;
//             for (int column = 0 ; column < source_matrix_size ; column++)
//             {
//                 if (column == delete_column) continue;
//                 matrix_change_element(source_matrix , row-1 , (column < delete_column ? column : column-1) , matrix_access(source_matrix , row , column , source_matrix_size) , source_matrix_size);
//             }
//         }
//         return new_matrix_size;
//     }
// }

//============================================================================//

void resize_SourceMatrix_to_NewMatrix(double source_matrix[] , int delete_row , int delete_column , int source_matrix_size , double new_matrix[])
{
    // cout << "\nStart_ressize \n"; //test

    if (source_matrix_size <= 1) cout << "can't resize this matrix >> source_matrix_size = 1";
    else
    {
        // cout << "delete_row : " << delete_row << "  delete_column : " << delete_column << "  source_matrix_size : " << source_matrix_size; //test

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

        // cout << "\n\n________SubMatrix_After_resize_________\n"; //test
        // show_matrix(new_matrix , new_matrix_size); //test
        // cout << "__________________________________________\n\n"; //test
    }
}

double DET_FUNCTION(double source_matrix[] ,long int source_matrix_size ,long int i)
{
    if (source_matrix_size == 1) return matrix_access(source_matrix , 0 , 0 , source_matrix_size);
    else if (i > source_matrix_size - 1) return 0;
    else
    {
        long int SubMatrix_Size;
        SubMatrix_Size = source_matrix_size - 1;
        // cout << "Before_Resize ||" << "source_matrix_size >> " << source_matrix_size << " SubMatrix_Size >> " << SubMatrix_Size << "\n"; //test
        double SubMatrix[SubMatrix_Size];
 
        resize_SourceMatrix_to_NewMatrix(source_matrix , 0 , i , source_matrix_size , SubMatrix);

        // cout << "After_Resize ||" << "source_matrix_size >> " << source_matrix_size << " SubMatrix_Size >> " << SubMatrix_Size << "\n"; //test
        // cout << "\n\n||||||||||||||||||||||------------------|||||||||||||||||||\n\n\n"; //test

        int pow_;
        if (i % 2 == 0) pow_ = 1;
        else pow_ = -1;

        return (matrix_access(source_matrix , 0 , i , source_matrix_size) * pow_ * DET_FUNCTION(SubMatrix , SubMatrix_Size , 0)) + (DET_FUNCTION(source_matrix , source_matrix_size , i+1));

    }
}