class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        // [1,3,4,8,7,9,3,5,1]
        // [1,1,3,3,4,5,7,8,9]

        // [1,3,3,2,7,3]
        // [1,2,3,3,3,7]
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i = 0;i<=n - 3;i+=3){
            int curr = nums[i];
            int next = nums[i+1];
            int nextNext = nums[i+2];

            if(abs(curr - next) <= k && abs(curr - nextNext) <= k){
                ans.push_back({curr,next,nextNext});
            }
            else{
                return {};
            }
        }
        return ans;

    }
};
