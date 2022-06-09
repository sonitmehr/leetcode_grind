class Solution {
public:
    
    int f(int ind, vector<int> &a,vector<int> &dp){
        if(ind == 0)return a[0];
        if(ind < 0)return 0;
        if(dp[ind]!=-1)return dp[ind];
        
        int l = a[ind] + f(ind-2,a,dp);
        int r = f(ind-1,a,dp);
        return dp[ind] = max(l,r);
    }
    
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        
        return f(n-1,nums,dp);

        
        
    }
};
