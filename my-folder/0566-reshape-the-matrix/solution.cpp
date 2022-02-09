class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if(mat.size()*mat[0].size() != r*c)
            return mat;
        vector<vector<int>> v(r,vector<int>(c));
        
        int row_count = 0;
        int col_count = 0;
        
        for(int i = 0;i<mat.size();i++){
            for(int j = 0;j<mat[0].size();j++){
                v[row_count][col_count] = mat[i][j];
                col_count++;
                if(col_count == c ){
                    col_count =0;
                    row_count++;
                }
            }
        }
        return v;
    }
}; 
