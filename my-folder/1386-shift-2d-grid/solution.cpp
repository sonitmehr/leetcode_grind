class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        //if(rows == 0)
        int col = grid[0].size();
        int temp ;
        int temp1;
        while(k--){
            int temp = grid[rows-1][col-1];
            int temp1 = -1;
            for(int i = rows-1;i>=0;i--){
                if(i>0)temp1 = grid[i-1][col-1];
                for(int j = col-1;j>=1;j--){
                    grid[i][j] = grid[i][j-1];
                }
                grid[i][0] = temp1;
            }
            grid[0][0] = temp;
        }
        
        return grid;
            
    }
};
