class Solution {
public:
    
    bool f(int i,int j,int n,int m,vector<vector<int>>& grid){
        if(i == n -1 && j == m - 1)return true;
        
        if(grid[i][j] == 0)return false;
        if(i + 1 < n){
            grid[i][j] = 0;
            if(f(i + 1,j,n,m,grid))return true;;
        }
        if(j + 1 < m){
            grid[i][j] = 0;
            if(f(i,j+1,n,m,grid))return true;
        }
        return false;
        
        
        
        
            
    }
    
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        int m = grid[0].size(),n = grid.size();
        
        if(f(0,0,n,m,grid) == false)return true;
        grid[0][0]= 1;
//         for(int i=0;i<n;i++){
//             for(int j = 0;j<m;j++){
//                 cout << grid[i][j] << " ";
                
//             }
//             cout << endl;
//         }
//         cout << endl;
        return !(f(0,0,n,m,grid));
        
    }
};
