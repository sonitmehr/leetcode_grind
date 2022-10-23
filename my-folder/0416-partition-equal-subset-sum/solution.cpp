class Solution {
public:
    
    bool f(int i,int target,vector<int> &a,vector<vector<int>> &dp){
        if(target == 0)return true;
        if(i == 0)return (target == a[0]);
        if(dp[i][target]!=-1)return dp[i][target];
        bool noPick = f(i-1,target,a,dp);
        bool pick = false;
        if(a[i] <= target){
            pick = f(i-1,target -a[i],a,dp);
        }
        return dp[i][target]= (pick | noPick);
        
        
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
