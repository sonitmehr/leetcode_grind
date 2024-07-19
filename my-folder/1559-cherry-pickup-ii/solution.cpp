class Solution {
public:
    bool check(int i, int j, int n, int m) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }

    int solve(int i, int j1, int j2, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        if (i == mat.size() - 1) {
            if (j1 == j2)
                return mat[i][j1];
            return mat[i][j1] + mat[i][j2];
        }

        int sum = 0;
        for (int dy1 = -1; dy1 <= 1; dy1++) {
            for (int dy2 = -1; dy2 <= 1; dy2++) {
                int y1 = j1 + dy1;
                int y2 = j2 + dy2;

                if (check(i, y1, n, m) && check(i, y2, n, m)) {
                    if (j1 == j2) {
                        sum = max(sum, mat[i][j1] + solve(i + 1, y1, y2, mat));
                    } else {
                        sum = max(sum, mat[i][j1] + mat[i][j2] +
                                           solve(i + 1, y1, y2, mat));
                    }
                }
            }
        }
        return sum;
    }

    int cherryPickup(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(m, 0)));

        for(int j1 = 0;j1<m;j1++){
            for(int j2= 0;j2<m;j2++){
                if(j1==j2){
                    dp[n - 1][j1][j2] = mat[n - 1][j1];
                }
                else{
                    dp[n -1 ][j1][j2] = mat[n - 1][j2] + mat[n - 1][j1];
                }
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j1 = 0; j1 < m; j1++) {
                for (int j2 = 0; j2 < m; j2++) {

                    // All 9 combinations for where I am coming from
                    int sum = 0;
                    for (int dy1 = -1; dy1 <= 1; dy1++) {
                        for (int dy2 = -1; dy2 <= 1; dy2++) {
                            int y1 = j1 + dy1;
                            int y2 = j2 + dy2;
                            if (check(i + 1, y1, n, m) &&
                                check(i + 1, y2, n, m)) {
                                if (j1 == j2) {
                                    sum = max(sum,
                                              dp[i + 1][y1][y2] + mat[i][j1]);
                                } else {
                                    sum = max(sum, mat[i][j1] + mat[i][j2] +
                                                       dp[i + 1][y1][y2]);
                                }
                            }
                        }
                    }
                    dp[i][j1][j2] = sum;
                }
            }
        }
       return dp[0][0][m - 1];
    }
};
