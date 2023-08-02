class Solution {
public:
    int dp[21][2001];
    int f(int i,vector<int>&a,int sum,int target){
        if(i == a.size()){
            if(sum == target)return 1;
            return 0;
        }
        if(dp[i][sum + 1000] != -1)return dp[i][sum + 1000];
        int one = f(i + 1,a,sum - a[i],target);
        int two = f(i + 1,a,sum + a[i],target);
        return dp[i][sum + 1000]= one + two;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return f(0,nums,0,target);
    }
};
