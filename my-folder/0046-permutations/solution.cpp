class Solution {
    
    // DO AGAIN.
    
    void permute(vector<vector<int>> &res, vector<int> nums, int low) {
        if(low == nums.size()) res.push_back(nums);
        else{
            for(int i = low; i < nums.size(); i++){
                swap(nums[i], nums[low]);
                permute(res, nums, low+1);
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        permute(res, nums, 0);
        return res;
    }
};
