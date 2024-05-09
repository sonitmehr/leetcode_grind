class Solution {
    public int lengthOfLIS(int[] nums) {
        int n = nums.length;
        int [] dp = new int [n + 1];
        int maxi = 0;
        for(int i = 0;i<n;i++){
            dp[i] = 1;
            for(int j = 0;j < i;j ++) {
                if(nums[i] > nums[j]  && dp[j] + 1 > dp[i] ){
                    dp[i] = dp[j] + 1;
                }
            }
            maxi = Math.max(dp[i],maxi);
        }
        return maxi;
    }
}
