#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
    private:
        int mat[3][3];
    
    public:
        Matrix();
        Matrix(int m[][3]);
        void print();
        void setMat(int m[][3]);
        int sumMat();
        int sumDiag(int d);
        int sumCol(int col);
        int sumRow(int row);
        bool getValue(int val);
        void setElement(int row, int col, int elem);
        int getElement(int row, int col);
        bool rowElementsEql(int row, int n);
        bool colElementsEql(int col, int n);
        bool diagElementsEql(int d, int n);
        
        Matrix operator+(Matrix A)
        {
            Matrix tmp;
            int elem;
            
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    elem = this->mat[i][j] + A.getElement(i, j);
                    tmp.setElement(i, j, elem);
                }
            }
            
            return tmp;
        }
        
};

#endif