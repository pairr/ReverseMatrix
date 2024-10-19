//
// Created by stud-05 on 10/19/24.
//

#ifndef MATRIXLIB_H
#define MATRIXLIB_H

#endif //MATRIXLIB_H

#include <cmath>
#include <vector>
#include <algorithm>
using std::vector;
using std::swap;
void transpose_line(vector<vector<double> >&Matr, int i, int j);
void relax(vector<vector<double> >&Matr, int i, double val);
void add(vector<vector<double> >&Matr, int to, int from, double val);
vector<vector<double> >reverse(vector<vector<double> >Matr);

