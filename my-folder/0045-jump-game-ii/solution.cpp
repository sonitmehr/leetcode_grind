class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1e9);
        dp[0] = 0;
        
        for(int i = 1;i<=nums[0];i++){
            if(i >= n)break;
            dp[i] = 1;
        }

        for(int i = 1;i<n;i++){
            int val = i + nums[i] ;
            if(val < n){
                for(int j = i;j<=val;j++){

                    dp[j] = min(1 + dp[i],dp[j]);
                }
            }
            else {
                dp[n - 1] = min(1 + dp[i],dp[n-1]);

            }
        }
        return dp[n -1 ];
    }
};
