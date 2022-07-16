class Solution {
private:
    int m;
    int n;
public:
    void assignVal(int m,int n){
        this->m = m;
        this->n = n;
    }
    int MOD = 1e9 + 7;
    
    long f(int m, int n, int maxMove, int startRow, int startColumn,vector<vector<vector<int>>> &dp){
        if(startRow < 0 || startRow >= m || startColumn >= n || startColumn < 0){
            return 1;
        }
        if(maxMove <= 0)return 0;
        
        if(dp[startRow][startColumn][maxMove]!=-1)return dp[startRow][startColumn][maxMove];
        
        //dp[m][n][maxMove] = 0;
        long long sum = 0;
        
        sum += (f(m,n,maxMove-1,startRow -1,startColumn,dp)%MOD + 
                f(m,n,maxMove-1,startRow ,startColumn-1,dp)%MOD + 
                f(m,n,maxMove-1,startRow,startColumn+1,dp)%MOD + 
                f(m,n,maxMove-1,startRow+1,startColumn,dp)%MOD);
        
        return dp[startRow][startColumn][maxMove] = sum%MOD;
        
//        return sum;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(n+1,vector<int>(maxMove + 1,-1)));
        
        
        //if(m==2 && n == 3 && maxMove == 8 && startRow == 1 && startColumn == 0)return 1104;
        return (int)f(m,n,maxMove,startRow,startColumn,dp);
    }
};
