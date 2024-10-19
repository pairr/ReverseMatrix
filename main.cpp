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
    SquareMatrix<double>M_rev = M.reverse();
    SquareMatrix<double>Id(A.size());
    Id.make_identity();

    M.show();
    cout << "\n";
    M_rev.show();
    cout << "\n";
    Id.show();
    cout << "\n";

    if(M * M_rev == Id)cout << "YES" << "\n";
    else cout << "NO" << "\n";
}
