class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<int> v;
        int n = nums.size();
        for(int i =0;i<n+1;i++){
            v.push_back(i);
            
        }
        int xorEle = v[0];
        for(int i = 1;i<n+1;i++){
            xorEle = xorEle^v[i];
        }
        int missing = nums[0];
        for(int i = 1;i<n;i++){
            missing = missing^nums[i];
        }
        return missing^xorEle;
    }
};
