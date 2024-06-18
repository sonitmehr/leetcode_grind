class Solution {
public:

    vector<vector<int>> twoSum(vector<int> &nums,int target,int l){
        int n = nums.size();
        int i = l,j = n - 1;
        vector<vector<int>> ans;
        while(i < j){
            int sum = nums[i] + nums[j];

            if(sum == target){
                ans.push_back({i,j});
                int left = nums[i],right = nums[j];
                while(i < j && nums[i] == left)i++;
                while(i < j && nums[j] == right)j--;

            }
            else if(sum < target){
                i++;
            }
            else j --;

        }
        return ans;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int sum = 0;
        //[-1,0,1,2,-1,-4]
        //[-4,-1,-1,0,1,2]
        vector<vector<int>> ans;
        for(int i= 0;i<n;i++){
            if(i > 0 && nums[i] == nums[i - 1])continue;
            int curr = nums[i];

            auto vec = twoSum(nums,-curr,i + 1);
            for(auto &i : vec){
                ans.push_back({curr,nums[i[0]],nums[i[1]]});
            }
        }

        return ans;
    }
};
