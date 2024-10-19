#include <iostream>
#include "MatrixLib.h"
using std::cout;
using std::cin;
int main()
{   int n;
    cin >> n;
    vector<vector<double> >A(n, vector<double>(n, 0));

    for(int i = 0; i < n; i++) {
        for(int j  = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    SquareMatrix<double>M(A);

    const vector<vector<double> > ans = M.reverse();

    for(int i = 0; i < n; i++) {
        for(int j  = 0; j < n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}
