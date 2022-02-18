class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        //we should return nums[0], if there only one house 

        if(n==1) return nums[0];  
        //1. Initialize an array dp sized according to state variable
        int *dp = new int[n];
        //2. Base cases to avoid index out of bounds
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i = 2; i<n; i++) {
        //3. Recurrence Relation
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        return dp[n-1];
    }
};
