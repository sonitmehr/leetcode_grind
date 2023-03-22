class Solution {
public:
int N = 9;
    bool check(int row,int col,char k,vector<vector<char>>& grid){
        for(int i= 0;i<9;i++){
            if(grid[row][i] == k)return false;
            if(grid[i][col] == k)return false;
            
            if(grid[3*(row/3) + i/3][3*(col/3) + i%3] == k)return false;
        }return true;
        
    }
    bool f(vector<vector<char>>& grid){
        
        
        
        for(int row = 0;row<N;row++){
            for(int col = 0;col<N;col++){
                if(grid[row][col] == '.'){
                    for(char k = '1';k<='9';k++){
                        if(check(row,col,k,grid)){
                            grid[row][col] = k;
                            if(f(grid) == true)return true;
                            grid[row][col] = '.';

                        }
                    }
                    return false;
                }
            }
        }
        return true;
        
    }
    void solveSudoku(vector<vector<char>>& grid) {
        f(grid);
        
    }
};
