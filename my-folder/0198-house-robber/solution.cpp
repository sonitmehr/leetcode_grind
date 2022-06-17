class Solution {
public:
    
    int f(int i,vector<int>&dp,vector<int>&a){
        if(i == 0)return a[0];
        else if(i < 0)return 0;
        if(dp[i]!=-1)return dp[i];
        
        int l = a[i] + f(i-2,dp,a);
        int r = f(i-1,dp,a);
        return dp[i] = max(l,r);
    }
    
    
    int rob(vector<int>& v) {
        int n = v.size();        
        vector<int> dp(n,-1);
        int l = INT_MIN;
        if(n == 1)return v[0];
        dp[0] = v[0];
        dp[1] = max(v[0],v[1]);
        for(int i = 2;i<n;i++){
            l = v[i] + dp[i-2];
            int r = dp[i-1];
            dp[i] = max(r,l);
        }
        
        return dp[n-1];
        
        
    }
};
