class Solution {
public:
    // similar question to maximum non adjacent sum 
    
    int  f(int index,vector<int>& nums,vector<int>&dp)
    {
        if(index==0)
            return nums[index];
        
        if(index<0)
        {
            return 0;
        }
        
        if(dp[index]!=-1)
        {
            return dp[index];
            
        }
        
        int robber= nums[index] + f(index-2,nums,dp);
        
        int not_robber= f(index - 1,nums,dp);
        
        return dp[index]= max(robber,not_robber);
    }
    
    int rob(vector<int>& nums)
    {
        int n=nums.size();
        vector<int>dp(n,-1);
        return f(n-1,nums,dp);
        
        
        
    }
};
