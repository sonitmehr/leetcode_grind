class Solution {
public:
    
    int f(int i,int j1,int j2,vector<vector<int>> &a,vector<vector<vector<int>>>&dp){
        if(j1 < 0 || j2 < 0 || j1 >= a[0].size() || j2 >=a[0].size() )return -1e8;
        if(i == a.size()-1){
            if(j1 == j2)return a[i][j1];
            return a[i][j1] + a[i][j2];
        }
        if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
        int maxi = -1e8;
        for(int alice = -1;alice<=1;alice++){
            for(int bob = -1;bob<=1;bob++){
                int val;
                if(j1 == j2)val = a[i][j1];
                else val = a[i][j1] + a[i][j2];
                
                val += f(i+1,j1+alice,j2+bob,a,dp);
                maxi = max(maxi,val);
                
            }
        }
        return dp[i][j1][j2] = maxi;
        
    }
    
    int cherryPickup(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(m+1,-1)));
        
        return f(0,0,m-1,a,dp);
        
    }
};
