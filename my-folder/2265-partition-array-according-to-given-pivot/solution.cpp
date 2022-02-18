class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> small,equal,big,finale;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] < pivot)small.push_back(nums[i]);
            else if(nums[i] > pivot)big.push_back(nums[i]);
            else equal.push_back(nums[i]);
        }
        for(int i = 0;i<small.size();i++)finale.push_back(small[i]);
        for(int i = 0;i<equal.size();i++)finale.push_back(equal[i]);
        for(int i = 0;i<big.size();i++)finale.push_back(big[i]);
        return finale;
    }
};
