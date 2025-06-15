/* Faatin Nur Husna binti Izmir
22010085
g2, medium, rotate matrix 180 degrees */

#include <iostream>
#include <vector>
using namespace std;

void rotateMatrix(vector<vector<int>>& mat) {
    int n = mat.size();

    vector<vector<int>> res(n, vector<int>(n));
  
    // move mat[i][j] to mat[n-i-1][n-j-1]
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res[i][j] = mat[n - i - 1][n - j - 1];
        }
    }
    mat = res;
}

int main() {
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    rotateMatrix(mat);
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[i].size(); j++) {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
