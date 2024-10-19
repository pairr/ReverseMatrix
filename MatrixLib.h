//
// Created by stud-05 on 10/19/24.
//

#ifndef MATRIXLIB_H
#define MATRIXLIB_H
#include <bits/unique_ptr.h>
#include <cmath>
#include <vector>
#include <algorithm>
#endif //MATRIXLIB_H
using std::vector;
using std::swap;
using std::unique_ptr;
using std::move;
using std::make_unique;
template<typename T>
class SquareMatrix
{
private:
    unique_ptr<vector<vector<T> >> matrix;
    int size = 0;

    void transpose_rows(int row1, int row2);
    void multiply_row(int row, T val);
    void add_to_row(int row_to, int row_from, T val);
    void make_identity();
public:
    explicit SquareMatrix(const vector<vector<T> >& m):matrix(make_unique<vector<vector<T> >>(m)), size(m.size()){}
    SquareMatrix(const SquareMatrix<T>& other):matrix(make_unique<vector<vector<T> >>(*other.matrix)), size(other.size){}
    explicit SquareMatrix(int s):matrix(make_unique<vector<vector<T> > >(s, vector<T>(s, 0))), size(s){}
    vector<vector<T> >reverse();
    vector<vector<T> >get_matrix();
};


