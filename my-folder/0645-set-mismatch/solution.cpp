class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int dup = -1;
        int missing = -1;

        for (int i = 0; i < n; i++) {
            int _abs = abs(nums[i]);
            if (nums[_abs - 1] < 0) {
                dup = _abs;
            } else {
                nums[_abs - 1] = -nums[_abs - 1];
            }
        }
        for(int i= 0;i<n;i++){
            if(nums[i] > 0){
                missing = i+1;
            }
        }


        return {dup, missing};
    }
};
