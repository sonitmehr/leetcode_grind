class Solution {
public:

    int solve(int i,int j,vector<int> &nums,vector<vector<int>> &dp){
        if(i > j)return 0;
if(dp[i][j] != -1)return dp[i][j];
        int ans = 0;

        for(int k = i;k<=j;k++){
            int coins = nums[i - 1] * nums[k] * nums[j + 1] + solve(i,k - 1,nums,dp) + solve(k + 1,j,nums,dp); 
            ans = max(ans,coins);
        }
        return dp[i][j] = ans;


    }

    int maxCoins(vector<int>& nums) {

        nums.insert(nums.begin(),1);
        nums.push_back(1);
vector<vector<int>> dp(nums.size() + 2,vector<int> (nums.size() + 2,-1));
        return solve(1,nums.    size() - 2,nums,dp);
    }
};
