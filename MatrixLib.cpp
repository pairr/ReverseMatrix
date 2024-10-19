//
// Created by stud-05 on 10/19/24.
//
#include "MatrixLib.h"
void transpose_line(vector<vector<double> >&Matr, int line1, int line2) {
    for(int column = 0; column < Matr.size(); column++) {
        swap(Matr[line1][column], Matr[line2][column]);
    }
}
void relax(vector<vector<double> >&Matr, int line, double val) {
    for(int column = 0; column < Matr.size(); column++)Matr[line][column] /= val;
}
void add(vector<vector<double> >&Matr, int line_to, int line_from, double val) {
    for(int column = 0; column < Matr.size(); column++) {
        Matr[line_to][column] += Matr[line_from][column] * val;
    }
}
vector<vector<double> >reverse(vector<vector<double> >Matr){
    int n = Matr.size();
    vector<vector<double> >Res(n, vector<double>(n, 0));
    for(int i = 0; i < n; i++)Res[i][i] = 1;

    for(int line = 0; line < n; line++) { // direct Gauss
        if(Matr[line][line] == 0) {
            for(int i = line + 1; i < n; i++)
                if(Matr[i][line] != 0) {
                    transpose_line(Matr, line, i);
                    transpose_line(Res, line, i);
                    break;
                }
        }
        relax(Res, line, Matr[line][line]);
        relax(Matr, line, Matr[line][line]);
        for(int i = line + 1; i < n; i++) {
            add(Res, i, line, -Matr[i][line]);
            add(Matr, i, line, -Matr[i][line]);
        }

    }

    for(int line = n - 1; line > 0; line--) { // reverse Gauss
        for(int i = line - 1; i >= 0; i--) {
            add(Res, i, line, -Matr[i][line]);
            add(Matr, i, line, -Matr[i][line]);
        }
    }
    return Res;
}

