class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int lastVal = 0;
        
        for(int i = 0;i<n;i++){
            if(nums[i] != val){
                nums[lastVal] = nums[i];
                lastVal++;
            }
        }
        return lastVal;
    }
};
