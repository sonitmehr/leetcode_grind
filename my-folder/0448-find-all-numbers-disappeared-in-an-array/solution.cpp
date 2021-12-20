class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0;i<nums.size();i++){
            nums[abs(nums[i])-1] = -abs(nums[abs(nums[i])-1]);
        }nums.clear();
        for(int i = 0;i<n;i++){
            if(nums[i]>0){
                nums.push_back(i+1);
                
            }
        }return nums;
    }
};
