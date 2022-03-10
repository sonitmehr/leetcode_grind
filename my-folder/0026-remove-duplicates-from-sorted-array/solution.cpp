class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int last = 1;
        int prev = nums[0];
        for(int i = 1;i<n;i++){
            if(nums[i] != prev){
                nums[last] = nums[i];
                last++;
                prev = nums[i];
                
            }
        }
        return last;
    }
};
