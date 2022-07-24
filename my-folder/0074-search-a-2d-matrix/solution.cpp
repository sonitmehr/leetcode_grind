class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int temp = -1;
        for(int i = 0;i<n;i++){
            if(matrix[i][0] < target && matrix[i][m-1] > target)temp = i;
            else if(matrix[i][0] == target || matrix[i][m-1] == target)return true;
        }
        if(temp != -1){
            for(int i = 0;i<m;i++){
                if(matrix[temp][i] == target)return true;
            }
        }
        return false; 
    }
};
