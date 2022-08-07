class Solution {
public:
    //int dp[100001];
    bool rec(int i,vector<int> &nums,int n,vector<int> &dp){
        if(i > n)return false;
        if(i==n){
            return dp[i]=true;
        }
        if(dp[i]!=-1){
            return dp[i];
        }    
        if(i+1<n && nums[i]==nums[i+1]){
            if(rec(i+2,nums,n,dp)==true){
                return true;
            }
            if(i+2<n && nums[i+2]==nums[i]){
                if(rec(i+3,nums,n,dp)==true){
                    return true;
                }
            }
        }
        else if((i+2<n && nums[i+1]==nums[i]+1) && (nums[i+2]==nums[i+1]+1)){
            if(rec(i+3,nums,n,dp)==true){
                return true;
            }    
        }
        return dp[i] = false;
    }
    
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(nums.size() + 1, -1);
        return rec(0,nums,n,dp);
    }
};
