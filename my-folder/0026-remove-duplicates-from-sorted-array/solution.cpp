class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1) return nums.size();
        int prev = nums[0], position = 1, temp;
        for (int i = 1; i < nums.size(); i++) {
            temp = nums[i];
            if(nums[i] != prev) {
                nums[position] = temp;
                position++;
            }
            prev = nums[i];
        }
        return position;
    }
};
