class Solution {
public:
    
    int f(int ind,vector<int> &dp,vector<int> &a){
        if(ind == 0)return a[0];
        else if(ind < 0)return 0;
        if(dp[ind]!=-1)return dp[ind];
        
        // To maximise maxi, we will always go to ind -2 after picking index;
        int pick = a[ind] + f(ind-2,dp,a);
        // When you don't pick, go to previous index.
        int notPick = 0 + f(ind-1,dp,a);
        return dp[ind] = max(pick,notPick);
        
        
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return nums[0];
        vector<int> dp(n+1,-1);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2;i<n;i++){
            
            int l = nums[i] + dp[i-2];
            int r =  dp[i-1];
            dp[i]= max(l,r);
             
            
        }
        return dp[n-1];
    }
};
