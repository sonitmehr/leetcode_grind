class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n = nums.size();
        int xori = n;
        for(int i = 0;i<n;i++){
            xori = (xori ^ nums[i]);
            xori = (xori ^ i);
        }
        return xori;
    }
};
