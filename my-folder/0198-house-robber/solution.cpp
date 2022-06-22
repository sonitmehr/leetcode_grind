class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        vector<int> dp(n,-1);
        int prev = nums[0];
        int l = nums[1];
        int prev2 = 0;
        for(int i = 1;i<n;i++){
            if(i > 1) l = nums[i] + prev2;
            int r = prev;
            int curri = max(l,r); 
            prev2 = prev;
            prev = curri;
        }
        return prev;
    }
        
};
