//
// Created by stud-05 on 10/19/24.
//
#include "MatrixLib.h"

template<typename T>
void SquareMatrix<T>::transpose_rows(const int row1, const int row2) {
    for(int column = 0; column < size; column++) {
        swap((*matrix)[row1][column], (*matrix)[row2][column]);
    }
}
template<typename T>
void SquareMatrix<T>::multiply_row(const int row, const T val) {
    for(int column = 0; column < size; column++)(*matrix)[row][column] *= val;
}
template<typename T>
void SquareMatrix<T>::add_to_row(const int row_to, const int row_from, const T val) {
    for(int column = 0; column < size; column++) {
        (*matrix)[row_to][column] += (*matrix)[row_from][column] * val;
    }
}
template <typename T>
void SquareMatrix<T>::make_identity()
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(i == j)(*matrix)[i][j] = 1;
            else (*matrix)[i][j] = 0;
        }
    }
}
template <typename T>
vector<vector<T>> SquareMatrix<T>::get_matrix()
{
    return *matrix;
}

template<typename T>
vector<vector<T> > SquareMatrix<T>::reverse(){
    SquareMatrix<T> Res(size);
    Res.make_identity();

    for(int row = 0; row < size; row++) { // direct Gauss
        if((*matrix)[row][row] == 0) {
            for(int i = row + 1; i < size; i++)
                if((*matrix)[i][row] != 0) {
                    Res.transpose_rows(row, i);
                    transpose_rows(row, i);
                    break;
                }
        }
        Res.multiply_row(row, 1.0 / (*matrix)[row][row]);
        multiply_row(row, 1.0 / (*matrix)[row][row]);
        for(int i = row + 1; i < size; i++) {
            Res.add_to_row(i, row, -(*matrix)[i][row]);
            add_to_row(i, row, -(*matrix)[i][row]);
        }

    }

    for(int row = size - 1; row > 0; --row) { // reverse Gauss
        for(int i = row - 1; i >= 0; --i) {
            Res.add_to_row(i, row, -(*matrix)[i][row]);
            add_to_row(i, row, -(*matrix)[i][row]);
        }
    }
    return Res.get_matrix();
}
template class SquareMatrix<double>;
