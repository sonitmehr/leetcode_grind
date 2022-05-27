class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
       // int sum = 0;
        
        if(n  <=4)return 0;
        
        // Kill 3 smallest elements
        long long ans = nums[n-1] - nums[3];

        // Kill 3 largest elements.;
        ans = min(ans,(long long)(nums[n-4]-nums[0]));

        // Kill 1 biggest and 2 smallest
        ans = min(ans,(long long)(nums[n-2] - nums[2]));

        // Kill 2 biggest and 1 smallest
        ans = min(ans,(long long)(nums[n-3] - nums[1]));
        return ans;
                
        
    }
};





// [0,1,1,4,6,6,6];
