class Solution {
    private:
    int helper(vector<int>&nums,int index,int dp[]){
        if(index>=nums.size()){
            return 0;
        }
        //include vala case:
        if(dp[index]!=-1)return dp[index];
        int a=nums[index]+helper(nums,index+2,dp);
        //exclude vala case
        int b=helper(nums,index+1,dp);
        dp[index]=max(a,b);
        return dp[index];
    }
public:
    int rob(vector<int>& nums) {
       int dp[nums.size()+1];
        memset(dp,-1,sizeof(dp));
        return helper(nums,0,dp);
    }
};
