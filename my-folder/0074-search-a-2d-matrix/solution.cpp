class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int col = matrix[0].size();
        int temp = -1;
        /*if(rows*col == 1){
            if(matrix[0][0] == target)return true;
            return false;
        }*/
        for(int i = 0;i<rows;i++){
            if(target > matrix[i][0] && target < matrix[i][col-1]) temp = i;
            else if(matrix[i][0] == target || matrix[i][col-1] == target) return true;
        }
        if(temp!=-1){
            for(int i = 0;i<col;i++){
                if(matrix[temp][i] == target)return true;
            }
        }
        return false;
    }
};
