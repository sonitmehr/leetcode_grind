class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> ans(m,vector<int>(n,0));
        int row = 0,col = 0;
        for(int i = 0;i <n;i++){
            for(int j = 0;j<m;j ++){
                ans[row][col] = matrix[i][j];
                row++;                
            }
            row =0;
            col++;
            
            
        }
        return ans;
    }
};
/*

[[1,2,3],
 [4,5,6]]

[[1,4],
 [2,5],
 [3,6]]


*/
