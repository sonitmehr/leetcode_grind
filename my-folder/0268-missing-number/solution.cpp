class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n+1);
        temp[0]=0;
        int xorEle1 = temp[0];
        for(int i = 1;i<=n;i++){
            temp[i] = i;
            xorEle1^=temp[i];
            
        }
        int xorEle = nums[0];
        for(int i = 1;i<n;i++){
            xorEle ^= nums[i];
        }
        return xorEle^xorEle1;
    }
};
