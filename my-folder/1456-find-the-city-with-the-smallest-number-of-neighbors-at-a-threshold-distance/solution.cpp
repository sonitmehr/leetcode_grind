class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int thresh) {
        vector<vector<int>> mat(n, vector<int>(n, 1e9));
        int ptr = 0;
        while (ptr < n) {
            mat[ptr][ptr] = 0;
            ptr++;
        }
        for (int i = 0; i < edges.size(); i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            int d = edges[i][2];
            mat[a][b] = d;
            mat[b][a] = d;
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }

        int mini = n + 1;
        int city = -1;
        for(int i = 0;i<n;i++){
            int cnt = 0;
            for(int j = 0;j<n;j++){
                if(mat[i][j] <= thresh)cnt++;
            }
            if(cnt <= mini){
                mini = cnt;
                city = i;
            }
        }
        return city;
    }
};
