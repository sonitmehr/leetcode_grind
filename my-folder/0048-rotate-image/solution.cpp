class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size(),m = mat[0].size();

        for(int i = 0;i<n;i++){
            for(int j= i;j<m;j++){
                swap(mat[i][j],mat[j][i]);
            }
        }
        for(int i = 0;i<n;i++){
            reverse(mat[i].begin(),mat[i].end());
        }
    }
};
