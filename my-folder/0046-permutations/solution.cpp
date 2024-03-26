class Solution {
public:

    void solve(int i ,vector<int> &nums,vector<int>&vec,vector<vector<int>> &ans){

        if(i == nums.size()){
            ans.push_back(nums);
            
        }
        if(i >= nums.size())return;

        for(int k = i;k<nums.size();k ++ ){
                swap(nums[i],nums[k]);                
            solve(i + 1,nums,vec,ans);
                swap(nums[i],nums[k]);                
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<int> vec;
        vector<vector<int>> ans;
        solve(0,nums,vec,ans);
        return ans;
    }
};
