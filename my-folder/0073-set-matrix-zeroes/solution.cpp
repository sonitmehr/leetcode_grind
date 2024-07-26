class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int col0 = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    mat[i][0] = 0;
                    if (j == 0) {
                        col0 = 0;
                    } else {

                        mat[0][j] = 0;
                    }
                }
            }
        }

        cout << col0 << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (mat[i][0] == 0) {
                    mat[i][j] = 0;
                }
                if (j != 0 && mat[0][j] == 0) {
                    mat[i][j] = 0;
                }
                // cout << i << " " << j << endl;
                // cout << endl;
                // for (int k = 0; k < n; k++) {
                //     for (int g = 0; g < m; g++) {
                //         cout << mat[k][g] << " ";
                //     }
                //     cout << endl;
                // }
            }
        }

        cout << endl;
        for (int k = 0; k < n; k++) {
            for (int g = 0; g < m; g++) {
                cout << mat[k][g] << " ";
            }
            cout << endl;
        }
        if (mat[0][0] == 0) {
            for (int i = 0; i < m; i++) {
                mat[0][i] = 0;
            }
        }
        if (col0 == 0) {
            for (int i = 0; i < n; i++) {
                mat[i][0] = 0;
            }
        }
        cout << endl;
        for (int k = 0; k < n; k++) {
            for (int g = 0; g < m; g++) {
                cout << mat[k][g] << " ";
            }
            cout << endl;
        }
    }
};
