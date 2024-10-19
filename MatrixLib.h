//
// Created by stud-05 on 10/19/24.
//

#ifndef MATRIXLIB_H
#define MATRIXLIB_H
#include <bits/unique_ptr.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
#endif //MATRIXLIB_H
using std::vector;
using std::swap;
using std::unique_ptr;
using std::move;
using std::make_unique;
using std::cout;
template<typename T>
class SquareMatrix
{
    unique_ptr<vector<vector<T> >> matrix;
    int size = 0;

    void transpose_rows(int row1, int row2);
    void multiply_row(int row, T val);
    void add_to_row(int row_to, int row_from, T val);
public:
    explicit SquareMatrix(const vector<vector<T> >& m):matrix(make_unique<vector<vector<T> >>(m)), size(m.size()){}
    SquareMatrix(const SquareMatrix<T>& other):matrix(make_unique<vector<vector<T> >>(*other.matrix)), size(other.size){}
    explicit SquareMatrix(int s):matrix(make_unique<vector<vector<T> > >(s, vector<T>(s, 0))), size(s){}

    SquareMatrix<T>reverse();
    vector<vector<T> >get_matrix();
    void make_identity();
    void show();

    SquareMatrix<T>& operator=(SquareMatrix<T> const &other);
    SquareMatrix<T> operator*(SquareMatrix<T> const &other);
    bool operator==(SquareMatrix<T> const &other);

    friend vector<T> operator*(SquareMatrix<T> const& M, vector<T> const& V)
    {
        if(M.size != V.size())throw std::invalid_argument("vector and matrix have different dimensions");
        vector<T> product(M.size, 0);
        for(int row = 0; row < M.size; row++)
        {
            for(int column = 0; column < M.size; column++)
            {
                product[row] += (*M.matrix)[row][column] * V[column];
            }
        }
        return product;
    }
};


