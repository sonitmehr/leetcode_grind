class Solution {
public:
    
    int f(int i,int j,int endX,int endY,vector<vector<int>>& a,int zero){
       
        if(j < 0 || i < 0 || j >= a[0].size() || i >= a.size())return 0;
         if(a[i][j] == -1)return 0;
        if(a[i][j] == 2)return zero == -1;
        a[i][j] = -1;
        zero--;
        
        int up = f(i-1,j,endX,endY,a,zero);
        int down = f(i+1,j,endX,endY,a,zero);
        int left = f(i,j-1,endX,endY,a,zero);
        int right = f(i,j+1,endX,endY,a,zero);
        int total = up + down + left + right;
        a[i][j] = 0;
        zero++;


        return total;
        
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int endX=0,endY=0,startX=0,startY=0;
        
        //vector<vector<int>> dp(m,vector<int>(n,-1));
        int zero = 0;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j] == 0)zero++;
                if(grid[i][j] == 1){
                    startX = i;
                    startY = j;
                }
                if(grid[i][j] == 2){
                    endX = i;
                    endY = j;
                }
                
            }
        }
        return f(startX,startY,endX,endY,grid,zero);
    }
};
