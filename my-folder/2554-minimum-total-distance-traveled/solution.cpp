class Solution {
public:
    
    long long solve(long long x,long long y,vector<int>&v,vector<int>&f,vector<vector<long long>> &dp){
        if(x == v.size())return 0;
        if(y == f.size())return 1e13;
        if(dp[x][y] != -1)return dp[x][y];
        long long ans = 1e13;
        ans = min(ans,solve(x + 1,y + 1,v,f,dp) + abs(v[x] - f[y]));
        ans = min(ans,solve(x,y+1,v,f,dp));
        
        return dp[x][y] = ans;
        
        
    }
    long long minimumTotalDistance(vector<int>& v, vector<vector<int>>& f) {
        vector<int> fact;
        for(auto i : f){
            for(long long j = 0;j<i[1];j++){
                fact.push_back(i[0]);
            }
        }
        int n = v.size();
        int m = fact.size();
        sort(v.begin(),v.end());
        sort(fact.begin(),fact.end());
        vector<vector<long long>> dp(n+1,vector<long long>(m+1,-1));
        
        return solve(0,0,v,fact,dp);
    }
};
