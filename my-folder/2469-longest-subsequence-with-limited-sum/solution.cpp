class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int q = queries.size();
        sort(nums.begin(),nums.end());
        for(int i = 1;i<n;i++)nums[i] += nums[i - 1];
        vector<int> ans(q,0);
        
        for(int i = 0;i<q;i++){
            auto it = upper_bound(nums.begin(),nums.end(),queries[i]);
            if(it == nums.begin())continue;
            //it--;
            //if(it!=nums.end())it++;
            ans[i] = it - nums.begin();
        }
        return ans;
    }
};
