class Solution {
public:
    
    bool f(int i,int sum,vector<int> &a,vector<vector<int>> &dp){
        if(sum == 0)return true;
        if(i == 0){
            if(sum == a[0])return true;
            return false;
        }
        if(dp[i][sum] != -1)return dp[i][sum];
        
        bool noPick = f(i-1,sum,a,dp);
        bool pick = false;
        if(sum >= a[i]){
            pick = f(i-1,sum - a[i],a,dp);
        }
        return dp[i][sum] = (pick | noPick);
        
    }
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        
        for(int i = 0;i<n;i++)sum += nums[i];
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        
        if(sum%2 == 0){
            return f(n-1,sum/2,nums,dp);
        }
        return false;
        
        
    }
};
