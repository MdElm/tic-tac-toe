#include <iostream>
#include "Matrix.h"

// The default constructor
Matrix::Matrix()
{
    
}

// a constructor with parameters
Matrix::Matrix(int m[][3])
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            mat[row][col] = m[row][col];
        }
    }
}

/*********************************************************
 *                       setMat                          *
 * This function set the element of the matrix of class. *
 * Its accepts a 3x3 matrix as an argument.              *
 *********************************************************/

void Matrix::setMat(int m[][3])
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            mat[row][col] = m[row][col];
        }
    }
}

/********************************************************
 *                       print                          *
 * This function prints the class matrix on the screen. *
 ********************************************************/

void Matrix::print()
{
    std::cout << "\n";
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            std::cout << mat[row][col] << "\t";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

/*************************************************************
 *                          sumMat                           *
 * This matrix return sum of all the elements of the matrix. *
 *************************************************************/

int Matrix::sumMat()
{
    int total = 0;
    
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            total += mat[row][col];
        }
    }
    
    return total;
}

/********************************************************
 *                       sumRow                         *
 * This function returns the sum of a specified row *
 * of the matrix.                                       *
 ********************************************************/

int Matrix::sumRow(int row)
{
    int total = 0;
    
    for (int i = 0; i < 3; i++)
    {
        total += mat[row-1][i];
    }
    
    return total;
}

/*****************************************************
 *                      sumCol                       *
 * This function returns the sum of specified column *
 * of the matrix.                                    *
 *****************************************************/

int Matrix::sumCol(int col)
{
    int total = 0;
    
    for (int i = 0; i < 3; i++)
    {
        total += mat[i][col-1];
    }
    
    return total;
}

/******************************************************************
 *                           sumDiag                              *
 * This function the sum of specified diagonal of the matrix.     *
 * the diagonal can be either pricipal(1) or oposite pricipal(2). *
 *****************************************************************/

int Matrix::sumDiag(int d)
{
    int total = 0;
    
    if (d == 1)
    {
        for (int i = 0; i < 3; i++)
        {
            total += mat[i][i];
        }
    }
    else if (d == 2)
    {
        for (int i = 0, j = 2; i < 3 && j >= 0; i++, j--)
        {
            total += mat[i][j];
        }
    }
    
    return total;
}

// This function checks if an element is in the matrix

bool Matrix::getValue(int val)
{
    bool value = false;
    
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if ( mat[row][col] == val )
                value = true;
        }
    }
    
    return value;
}

void Matrix::setElement(int row, int col, int elem)
{
    mat[row][col] = elem;
}

int Matrix::getElement(int row, int col)
{
    return mat[row][col];
}

bool Matrix::rowElementsEql(int row, int n)
{
    bool equal = false;
    int count = 0;
    
    for (int i = 0; i < 3; i++)
    {
        if ( mat[row][i] == n )
            count++;
    }
    
    if (count == 3)
        equal = true;
    
    return equal;
}

bool Matrix::colElementsEql(int col, int n)
{
    bool equal = false;
    int count = 0;
    
    for (int i = 0; i < 3; i++)
    {
        if ( mat[i][col] == n )
            count++;
    }
    
    if (count == 3)
        equal = true;
    
    return equal;
}

bool Matrix::diagElementsEql(int d, int n)
{
    bool equal = false;
    int count = 0;
    
    if ( d == 1 )
    {
        
        for (int i = 0; i < 3; i++)
        {
            if ( mat[i][i] == n )
                count++;
        }
        
        if (count == 3)
            equal = true;
        
    }
    else if ( d == 2 )
    {
        
        for (int i = 0, j = 2; i < 3 && j >= 0; i++, j--)
        {
            if ( mat[i][j] == n )
                count++;
        }
        
        if (count == 3)
            equal = true;
    }
    
    return equal;
}