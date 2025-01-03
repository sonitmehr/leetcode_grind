class Solution {
public:

    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;

        for(auto &i : nums)sum += i;

        long long ans = 0;
        long long pre = 0;
        for(int i = 0;i<n- 1;i++)
        {   
            pre += nums[i];
            sum -= nums[i];

            if(pre >= sum)ans++;
            
        }
        return ans;

    }
};
