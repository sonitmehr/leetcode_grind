class Solution {
public:
    int dp[201][20001];
    bool f(int i ,int k,vector<int>&a){
        if(k == 0)return true;
        if(i >= a.size())return false;
        if(k < 0)return false;
        
        
        if(dp[i][k] != -1)return dp[i][k];
        bool one = false;
        if(k - a[i] >= 0)one = f(i + 1,k - a[i],a);
        return dp[i][k] = one | f(i + 1,k,a);

    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0;i<n;i++)sum += nums[i];
        if(sum%2 == 1)return false;
        memset(dp,-1,sizeof(dp));

        return f(0,sum/2,nums);
    }
};
