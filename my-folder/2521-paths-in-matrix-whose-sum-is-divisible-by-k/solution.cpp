class Solution {
public:
    
    int M = 1e9 + 7;
    long long f(int i,int j,int sum,int k,vector<vector<int>>&a,vector<vector<vector<int>>> &dp){
        if(i >= a.size()  || i < 0 || j >= a[0].size() || j < 0)return 0;
        if(i == a.size()-1 && j == a[0].size()- 1){
            //cout << i << " " << j <<  " " << sum + a[i][j] << endl;
            if((sum+a[i][j])%k == 0)return 1;
            
            return 0;
        }
        if(dp[i][j][sum%k] != -1)return dp[i][j][sum%k];
        
        //cout << i << " " << j <<  " " << sum << endl;
        
        int down = f(i + 1,j,(sum+a[i][j]),k,a,dp);
        
        int right = f(i,j+ 1,(sum+a[i][j]),k,a,dp);
        
        return dp[i][j][sum%k] = down%M + right%M;
        
    }
    
    int numberOfPaths(vector<vector<int>>& v, int k) {
        int n = v.size();
        int m = v[0].size();
        int sum = 0;
        
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(k + 1,-1)));
        return f(0,0,0,k,v,dp)%M;
        
    }
};
