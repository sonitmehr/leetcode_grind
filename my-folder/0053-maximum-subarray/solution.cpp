class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSub = nums[0];
        int curSum = 0;
        
        for (auto i : nums){
            if(curSum<0){
                curSum = 0;
                
            }
            curSum += i;
            maxSub = max(maxSub,curSum);
        }
        return maxSub;
    }
};
