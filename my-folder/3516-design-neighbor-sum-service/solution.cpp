class neighborSum {
public:
    vector<vector<int>> mat;
    bool check(int i,int j,int n,int m){
        return i >= 0 && j >= 0 && i < n && j < m;
        
    }
    neighborSum(vector<vector<int>>& grid) {
        mat = grid;
    }
    
    int adjacentSum(int value) {
        int n = mat.size();
        vector<int> dx = {-1,1,0,0};
        vector<int> dy = {0,0,1,-1};
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(mat[i][j] == value){
                    for(int k = 0;k<=3;k++){
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if(check(x,y,n,n)){
                            ans += mat[x][y];
                        }
                    }
                }
            }
        }
        return ans;
    }
    
    int diagonalSum(int value) {
        int n = mat.size();
        vector<int> dx = {-1,1,1,-1};
        vector<int> dy = {-1,-1,1,1};
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(mat[i][j] == value){
                    for(int k = 0;k<=3;k++){
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if(check(x,y,n,n)){
                            ans += mat[x][y];
                        }
                    }
                }
            }
        }
        return ans;
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */
