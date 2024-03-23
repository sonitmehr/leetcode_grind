class Solution {
public:
    int dp[101];
    int f(int i,vector<int> &a){
        if(i < 0)return 0;
        
        if(dp[i] != -1)return dp[i];
        int pick = a[i] + f(i-2,a);
        int noPick = f(i-1,a);

        return dp[i]=max(pick,noPick); 
    }

    int rob(vector<int>& nums) {
        memset(dp,0,sizeof(dp));
        int n = nums.size();
        if(n == 1)return nums[0];
        dp[0] = nums[0];
        dp[1] = max(dp[0],nums[1]);
        for(int i = 2;i<n;i++){
            int pick = nums[i] + dp[i - 2];
            // if(i-2 >= 0){
            //     pick += dp[i -2];
            // }
            int noPick = dp[i - 1];
            dp[i] = max(pick,noPick);
        }
        return dp[n - 1];
    }
};
