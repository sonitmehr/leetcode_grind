class Solution {
public:
    vector<vector<int>> twoSum(vector<int> &nums,long long target,int l){
        int n = nums.size();
        int i = l,j = n - 1;
        vector<vector<int>> ans;
        while(i < j){
            long long sum = nums[i] + nums[j];

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
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i= 0;i<n - 1;i++){
            if(i > 0 && nums[i] == nums[i -1 ])continue;
            for(int j = i + 1;j<n;j++){
                if(j > i + 1 && nums[j] == nums[j -1 ])continue;

                long long rem = (long long)target - nums[i] - nums[j];
                auto p = twoSum(nums,rem,j + 1);
                
                for(auto &k : p){
                    ans.push_back({nums[i],nums[j],nums[k[0]],nums[k[1]]});
                }  
            }
        }
        return ans;
    }
};
